#pragma once
#include <optional>
#include <string>
#include "Token.h"

struct ContextToken
{
    std::optional<Token> token;
    std::string lexeme;
    std::size_t lineNumber;
    std::size_t columnNumber;
};