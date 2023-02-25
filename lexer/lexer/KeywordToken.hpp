#pragma once

#include "Token.h"
#include "string"
// clang-format off

template <Token T>
struct KeywordToken
{
    static std::string Get() { return {}; }
};

template <>
struct KeywordToken<Token::If>
{
    static std::string Get() { return "if"; }
};

template <>
struct KeywordToken<Token::Else>
{
    static std::string Get() { return "else"; }
};

template <>
struct KeywordToken<Token::Do>
{
    static std::string Get() { return "do"; }
};

template <>
struct KeywordToken<Token::While>
{
    static std::string Get() { return "while"; }
};

template <>
struct KeywordToken<Token::For>
{
    static std::string Get() { return "for"; }
};

template <>
struct KeywordToken<Token::Int>
{
    static std::string Get() { return "int"; }
};

template <>
struct KeywordToken<Token::Double>
{
    static std::string Get() { return "double"; }
};

template <>
struct KeywordToken<Token::Bool>
{
    static std::string Get() { return "bool"; }
};

// clang-format on
