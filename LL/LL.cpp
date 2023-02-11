#include <fstream>
#include <iostream>
#include <string>
#include "LLParser.h"

using namespace std;

int main()
{
    // invalid 1
    setlocale(LC_ALL, "Russian");
    ifstream input("input.txt");
    string str{ istreambuf_iterator<char>(input), istreambuf_iterator<char>() };
    
    try
    {
        LLParser parser;
        parser.parse(str);
    }
    catch (std::exception& e)
    {
        cout << e.what();
    }
    return 0;
}
