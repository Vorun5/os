#pragma once

#include <unordered_map>
#include <vector>
#include <map>
#include <sstream>

#include "ContextToken.h"

class Lexer 
{
public:
    std::vector<ContextToken> Parse(std::string& inputText);

private:
    static std::optional<Token> MatchTwoSymbolTokens(char ch1, char ch2);
    static std::optional<Token> MatchOneSymbolTokens(char ch);
    static std::optional<Token> MatchKeywordTokens(std::string str);
    
    std::pair<Token, std::string> ParseIdentifier(std::istream& input);
    void SkipWhitespaces(std::istream& input);

    static bool IsIdentifierStart(char ch);
    static bool IsIdentifierSymbol(char ch);

    int GetChar(std::istream& input);
    void NextLine();

    size_t m_lineNumber = 1, m_columnNumber = 1;

    static inline std::map<std::string, Token> keywordTokensMap = {
        {"int", Token::Int},
        {"double", Token::Double},
        {"for", Token::For},
        {"while", Token::While},
        {"do", Token::Do},
        {"else", Token::Else},
        {"if", Token::If},
        {"bool", Token::Bool},
    };
    
    static inline std::map<char, Token> oneSymbolTokensMap = {
        {'+', Token::Plus},
        {'-', Token::Minus},
        {'*', Token::Asterisk},
        {'/', Token::Slash},
        {'=', Token::Assignment},
        {'<', Token::Less},
        {'>', Token::Greater},
        {',', Token::Comma},
        {'.', Token::Dot},
        {':', Token::Colon},
        {';', Token::Semicolon},
        {'(', Token::LeftParenthesis},
        {')', Token::RightParenthesis},
        {'{', Token::OpeningCurlyBrace},
        {'}', Token::ClosingCurlyBrace},
        {'[', Token::OpeningSquareBrace},
        {']', Token::ClosingSquareBrace},
    };

    static inline std::map<std::string, Token> twoSymbolTokensMap = {
        {"==", Token::Equal},
        {"!=", Token::NotEqual},
        {"<=", Token::LessEqual},
        {">=", Token::GreaterEqual},
        {"::", Token::DoubleColon},
        {"->", Token::RightArrow},
        {"/*", Token::CommentOpening},
        {"*/", Token::CommentEnding},
    };
};
