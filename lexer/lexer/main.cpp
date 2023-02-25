#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "ContextTokenLogger.h"

int main()
{
    Lexer lexer;
    std::string input = R"(10+a>2;)";

//     std::string input = R"(
//     int main(int argc, argv[])
//     {
//         bool flag = argc > 2;
//         do
//         {
//                 if (x->prop >= -10)
//                 {
//                     /* z = 5.23 - 0 + 12 * 23 / 45; */
//                     flag = z <= 2;
//                 }
//         } while (x == x);
//
//         v.y = std::string() != x < (flag > argc);
//     })";
    
    auto result = lexer.Parse(input);

    ContextTokenLogger::SetOutputStream(std::cout);
    ContextTokenLogger::Log(result);
}
