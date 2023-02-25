#include "NumberParser.h"
#include <sstream>

bool NumberParser::IsNumberStart(char value)
{
    return std::isdigit(value);
}

std::tuple<Token, std::string> NumberParser::Parse(std::istream& input)
{
    const auto number = ReadNumber(input);
    return {ParseNumber(number), number};
}

std::string NumberParser::ReadNumber(std::istream& input)
{
    bool pointFound = false;
    std::string result;

    while (input && (std::isalnum(input.peek()) || input.peek() == '.'))
    {
        if (input.peek() == '.')
            if (!pointFound)
            {
                pointFound = true;   
            }
            else
            {
                return result;   
            }

        result += input.get();
    }

    return result;
}

Token NumberParser::ParseNumber(const std::string& number)
{
    if (number.length() == 1)
    {
        return Token::IntegerNumericLiteral;
    }
    
    return ParseInteger(number);
}

Token NumberParser::ParseInteger(const std::string& number)
{
    for (std::size_t i = 0; i < number.length(); ++i)
    {
        auto& ch = number.at(i);
        if (!std::isdigit(ch))
        {
            if (ch == '.')
            {
                return ParseFloatingPoint(number.substr(i + 1));
            }

            return Token::Error;
        }
    }

    return Token::IntegerNumericLiteral;
}

Token NumberParser::ParseFloatingPoint(const std::string& number)
{
    for (auto ch : number)
    {
        if (!std::isdigit(ch))
        {
            return Token::Error;
        }
    }

    return number.size() ? Token::FloatingPointNumberLiteral : Token::Error;
}

bool NumberParser::IsHexDigit(char ch)
{
    return std::isdigit(ch) || ('A' <= std::toupper(ch) && std::toupper(ch) <= 'F');
}

bool NumberParser::IsBinaryDigit(char ch)
{
    return ch == '0' || ch == '1';
}

bool NumberParser::IsOctalDigit(char ch)
{
    return '0' <= ch && ch <= '7';
}
