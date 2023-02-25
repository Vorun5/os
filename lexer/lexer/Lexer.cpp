#include <optional>
#include <algorithm>
#include "Lexer.h"
#include "NumberParser.h"

std::vector<ContextToken> Lexer::Parse(std::string& inputText)
{
    std::istringstream input(inputText);
    std::vector<ContextToken> result;
    while (input)
    {
        SkipWhitespaces(input);

        char firstChar;
        ContextToken tokWCtx;
        tokWCtx.token = Token::Error;
        tokWCtx.lineNumber = m_lineNumber;
        tokWCtx.columnNumber = m_columnNumber;

        if (IsIdentifierStart(input.peek()))
        {
            std::tie(tokWCtx.token, tokWCtx.lexeme) = ParseIdentifier(input);
        }
        else if (NumberParser::IsNumberStart(input.peek()))
        {
            std::tie(tokWCtx.token, tokWCtx.lexeme) = NumberParser::Parse(input);
            m_columnNumber += tokWCtx.lexeme.size();
        }
        else if (auto oneSymbolTok = MatchOneSymbolTokens(firstChar = GetChar(input)))
        {
            std::optional<Token> twoSymbolTok;
            if (input && (twoSymbolTok = MatchTwoSymbolTokens(firstChar, input.peek())))
            {
                tokWCtx.token = *twoSymbolTok;
                (tokWCtx.lexeme += firstChar) += std::to_string(GetChar(input));
            }
            else
            {
                tokWCtx.token = *oneSymbolTok;
                tokWCtx.lexeme += firstChar;
            }
        }
        else if (auto twoSymbolTok = MatchTwoSymbolTokens(firstChar, input.peek()))
        {
            tokWCtx.token = *twoSymbolTok;
            (tokWCtx.lexeme += firstChar) += GetChar(input);
        }
        else
        {
            tokWCtx.lexeme += firstChar;
        }

        if (input) result.emplace_back(std::move(tokWCtx));
    }

    return result;
}

void Lexer::SkipWhitespaces(std::istream& input)
{
    char ch;
    while (std::isspace(ch = input.peek()))
    {
        if (ch == '\n')
        {
            NextLine();
        }

        GetChar(input);
    }
}

bool Lexer::IsIdentifierStart(const char ch)
{
    return ch == '_' || std::isalpha(ch);
}

bool Lexer::IsIdentifierSymbol(const char ch)
{
    return ch == '_' || std::isalnum(ch);
}

int Lexer::GetChar(std::istream& input)
{
    ++m_columnNumber;
    return input.get();
}

void Lexer::NextLine()
{
    ++m_lineNumber;
    m_columnNumber = 0;
}

std::optional<Token> Lexer::MatchTwoSymbolTokens(const char ch1, const char ch2)
{
    const std::string lexeme = "" + ch1 + ch2;
    if (const auto it = twoSymbolTokensMap.find(lexeme); it != twoSymbolTokensMap.end())
    {
        return it->second;
    }
    
    return std::nullopt;
}

std::optional<Token> Lexer::MatchOneSymbolTokens(const char ch)
{
    if (const auto it = oneSymbolTokensMap.find(ch); it != oneSymbolTokensMap.end())
    {
        return it->second;
    }
 
    return std::nullopt;
}

std::optional<Token> Lexer::MatchKeywordTokens(std::string str)
{
    std::ranges::transform(str, str.begin(), [](const unsigned char c)
    {
        return std::tolower(c);
    });
    if (const auto it = keywordTokensMap.find(str); it != keywordTokensMap.end())
    {
        return it->second;
    }
    
    return std::nullopt;
}

std::pair<Token, std::string> Lexer::ParseIdentifier(std::istream& input)
{
    std::string result;

    while (input && IsIdentifierSymbol(input.peek()))
        result.push_back(GetChar(input));

    if (std::optional<Token> token = MatchKeywordTokens(result))
    {
        return {*token, result};
    }

    return {Token::Identifier, result};
}
