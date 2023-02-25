#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "ContextTokenLogger.h"

int main()
{
    Lexer lexer;
    std::string input = R"(
    int main(int argc, double* argv[])
    {
        bool flag = argc;
        do
        {
                if (x->prop >= 0b00111)
                {
                    /* z = 5.23 - 00342 + 0xFFE98 * 23 / 45; */
                    flag = z <= 2;
                }
        } while (x == x);

        v.y = std::string() != x < (flag > argc);
    })";
    
    auto result = lexer.Parse(input);

    // std::ostringstream oss;
    ContextTokenLogger::SetOutputStream(std::cout);
    ContextTokenLogger::Log(result);
}
