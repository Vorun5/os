#pragma once

#include "Token.h"

// clang-format off

template <Token T>
struct OneSymbolToken
{
    static bool Match(char ch) { return false; }
};

template <>
struct OneSymbolToken<Token::Plus>
{
    static bool Match(char ch) { return ch == '+'; }
};

template <>
struct OneSymbolToken<Token::Minus>
{
    static bool Match(char ch) { return ch == '-'; }
};

template <>
struct OneSymbolToken<Token::Asterisk>
{
    static bool Match(char ch) { return ch == '*'; }
};

template <>
struct OneSymbolToken<Token::Slash>
{
    static bool Match(char ch) { return ch == '/'; }
};

template <>
struct OneSymbolToken<Token::Assignment>
{
    static bool Match(char ch) { return ch == '='; }
};

template <>
struct OneSymbolToken<Token::Less>
{
    static bool Match(char ch) { return ch == '<'; }
};

template <>
struct OneSymbolToken<Token::Greater>
{
    static bool Match(char ch) { return ch == '>'; }
};

template <>
struct OneSymbolToken<Token::Comma>
{
    static bool Match(char ch) { return ch == ','; }
};

template <>
struct OneSymbolToken<Token::Dot>
{
    static bool Match(char ch) { return ch == '.'; }
};

template <>
struct OneSymbolToken<Token::Colon>
{
    static bool Match(char ch) { return ch == ':'; }
};

template <>
struct OneSymbolToken<Token::Semicolon>
{
    static bool Match(char ch) { return ch == ';'; }
};

template <>
struct OneSymbolToken<Token::LeftParenthesis>
{
    static bool Match(char ch) { return ch == '('; }
};

template <>
struct OneSymbolToken<Token::RightParenthesis>
{
    static bool Match(char ch) { return ch == ')'; }
};

template <>
struct OneSymbolToken<Token::OpeningCurlyBrace>
{
    static bool Match(char ch) { return ch == '{'; }
};

template <>
struct OneSymbolToken<Token::ClosingCurlyBrace>
{
    static bool Match(char ch) { return ch == '}'; }
};

template <>
struct OneSymbolToken<Token::OpeningSquareBrace>
{
    static bool Match(char ch) { return ch == '['; }
};

template <>
struct OneSymbolToken<Token::ClosingSquareBrace>
{
    static bool Match(char ch) { return ch == ']'; }
};

// clang-format on
