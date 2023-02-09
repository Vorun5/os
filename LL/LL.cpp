#include <iostream>
#include <string>
#include "LLParser.h"

using namespace std;

// TODO: assign not work
int main()
{
    const string input = "PROG id\nVAR id : int;\nBEGIN\nREAD(id,id);\nWRITE(id,id,id);\nEND";
    // string input =
    //     "PROG id\nVAR id : int;\nBEGIN\nREAD(id,id);\nId := id+12*-(-12+id*id-12*(id+-12));\nWRITE(id,id,id);\nEND";
    LLParser parser;
    try
    {
        parser.parse(input);
    }
    catch (std::exception& e)
    {
        cout << e.what();
    }
    return 0;
}
