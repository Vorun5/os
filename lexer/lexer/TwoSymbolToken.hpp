#pragma once

#include "Token.h"

// clang-format off

template <Token T>
struct TwoSymbolToken
{
    static bool Match(char ch1, char ch2) { return false; }
};

template <>
struct TwoSymbolToken<Token::Equal>
{
    static bool Match(char ch1, char ch2) { return ch1 == '=' && ch2 == '='; }
};

template <>
struct TwoSymbolToken<Token::NotEqual>
{
    static bool Match(char ch1, char ch2) { return ch1 == '!' && ch2 == '='; }
};

template <>
struct TwoSymbolToken<Token::LessEqual>
{
    static bool Match(char ch1, char ch2) { return ch1 == '<' && ch2 == '='; }
};

template <>
struct TwoSymbolToken<Token::GreaterEqual>
{
    static bool Match(char ch1, char ch2) { return ch1 == '>' && ch2 == '='; }
};

template <>
struct TwoSymbolToken<Token::DoubleColon>
{
    static bool Match(char ch1, char ch2) { return ch1 == ':' && ch2 == ':'; }
};

template <>
struct TwoSymbolToken<Token::RightArrow>
{
    static bool Match(char ch1, char ch2) { return ch1 == '-' && ch2 == '>'; }
};

template <>
struct TwoSymbolToken<Token::CommentOpening>
{
    static bool Match(char ch1, char ch2) { return ch1 == '/' && ch2 == '*'; }
};

template <>
struct TwoSymbolToken<Token::CommentEnding>
{
    static bool Match(char ch1, char ch2) { return ch1 == '*' && ch2 == '/'; }
};

// clang-format on
