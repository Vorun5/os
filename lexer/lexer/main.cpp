#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "TokenLogger.h"

int main()
{
    Lexer lexer;
    std::string input = "if else while do 1w for int double";
    auto result = lexer.Parse(input);

    // std::ostringstream oss;
    TokenLogger::SetOutputStream(std::cout);
    TokenLogger::Log(result);
}
