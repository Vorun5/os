#include <optional>

#include "Lexer.h"
#include "NumberParser.h"

std::vector<TokenWithContext> Lexer::Parse(std::string& inputText)
{
    std::istringstream input(inputText);
    
    std::vector<TokenWithContext> result;

    while (input)
    {
        SkipWhitespaces(input);

        char firstChar;
        TokenWithContext tokWCtx;
        tokWCtx.token = Token::Error;
        tokWCtx.lineNumber = m_lineNum;
        tokWCtx.columnNumber = m_colNum;

        if (IsIdentifierStart(input.peek()))
        {
            std::tie(tokWCtx.token, tokWCtx.lexeme) = ParseIdentifier(input);
        }
        else if (NumberParser::IsNumberStart(input.peek()))
        {
            std::tie(tokWCtx.token, tokWCtx.lexeme) = NumberParser::Parse(input);
            m_colNum += tokWCtx.lexeme.size();
        }
        else if (auto oneSymbolTok = MatchOneSymbolTokens(firstChar = GetChar(input)))
        {
            std::optional<Token> twoSymbolTok;
            if (input && (twoSymbolTok = MatchTwoSymbolTokens(firstChar, input.peek())))
            {
                tokWCtx.token = *twoSymbolTok;
                (tokWCtx.lexeme += firstChar) += GetChar(input);
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
            NextLine();

        GetChar(input);
    }
}

bool Lexer::IsIdentifierStart(char ch)
{
    return ch == '_' || std::isalpha(ch);
}

bool Lexer::IsIdentifierSymbol(char ch)
{
    return ch == '_' || std::isalnum(ch);
}

int Lexer::GetChar(std::istream& input)
{
    ++m_colNum;
    return input.get();
}

void Lexer::NextLine()
{
    ++m_lineNum;
    m_colNum = 0;
}

std::optional<Token> Lexer::MatchTwoSymbolTokens(char ch1, char ch2)
{
    if (TwoSymbolToken<Token::Equal>::Match(ch1, ch2)) return Token::Equal;
    if (TwoSymbolToken<Token::NotEqual>::Match(ch1, ch2)) return Token::NotEqual;
    if (TwoSymbolToken<Token::LessEqual>::Match(ch1, ch2)) return Token::LessEqual;
    if (TwoSymbolToken<Token::GreaterEqual>::Match(ch1, ch2)) return Token::GreaterEqual;
    if (TwoSymbolToken<Token::DoubleColon>::Match(ch1, ch2)) return Token::DoubleColon;
    if (TwoSymbolToken<Token::RightArrow>::Match(ch1, ch2)) return Token::RightArrow;
    if (TwoSymbolToken<Token::CommentOpening>::Match(ch1, ch2)) return Token::CommentOpening;
    if (TwoSymbolToken<Token::CommentEnding>::Match(ch1, ch2)) return Token::CommentEnding;

    return std::nullopt;
}

std::optional<Token> Lexer::MatchOneSymbolTokens(char ch)
{
    if (OneSymbolToken<Token::Plus>::Match(ch)) return Token::Plus;
    if (OneSymbolToken<Token::Minus>::Match(ch)) return Token::Minus;
    if (OneSymbolToken<Token::Asterisk>::Match(ch)) return Token::Asterisk;
    if (OneSymbolToken<Token::Slash>::Match(ch)) return Token::Slash;
    if (OneSymbolToken<Token::Assignment>::Match(ch)) return Token::Assignment;
    if (OneSymbolToken<Token::Less>::Match(ch)) return Token::Less;
    if (OneSymbolToken<Token::Greater>::Match(ch)) return Token::Greater;
    if (OneSymbolToken<Token::Comma>::Match(ch)) return Token::Comma;
    if (OneSymbolToken<Token::Dot>::Match(ch)) return Token::Dot;
    if (OneSymbolToken<Token::Colon>::Match(ch)) return Token::Colon;
    if (OneSymbolToken<Token::Semicolon>::Match(ch)) return Token::Semicolon;
    if (OneSymbolToken<Token::LeftParenthesis>::Match(ch)) return Token::LeftParenthesis;
    if (OneSymbolToken<Token::RightParenthesis>::Match(ch)) return Token::RightParenthesis;
    if (OneSymbolToken<Token::OpeningCurlyBrace>::Match(ch)) return Token::OpeningCurlyBrace;
    if (OneSymbolToken<Token::ClosingCurlyBrace>::Match(ch)) return Token::ClosingCurlyBrace;
    if (OneSymbolToken<Token::OpeningSquareBrace>::Match(ch)) return Token::OpeningSquareBrace;
    if (OneSymbolToken<Token::ClosingSquareBrace>::Match(ch)) return Token::ClosingSquareBrace;
 
    return std::nullopt;
}

std::optional<Token> Lexer::MatchKeywordTokens(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
    {
        return std::tolower(c);
    });

    if (str == KeywordToken<Token::Int>::Get()) return Token::Int;
    if (str == KeywordToken<Token::Double>::Get()) return Token::Double;
    if (str == KeywordToken<Token::Bool>::Get()) return Token::Bool;
    if (str == KeywordToken<Token::If>::Get()) return Token::If;
    if (str == KeywordToken<Token::Else>::Get()) return Token::Else;
    if (str == KeywordToken<Token::Do>::Get()) return Token::Do;
    if (str == KeywordToken<Token::While>::Get()) return Token::While;
    if (str == KeywordToken<Token::For>::Get()) return Token::For;

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
