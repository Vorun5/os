#pragma once
#include <vector>
#include "Token.h"

using namespace std;

class LLParser
{
public:
    explicit LLParser()
        : m_index(0)
    {
    }

    void parse(const string& input);

private:
    size_t m_index;
    vector<Token> m_tokens;

    vector<Token> lexer(const string& program);
    
    void Expected(const std::string& expected) const;

    void ErrorLog(const std::string& message) const;
    
    bool match(TokenType expected);

    bool parsePROG();

    bool parseVAR();

    bool parseIDLIST();

    bool parseLISTST();

    bool parseTYPE();

    bool parseST();

    bool parseREAD();

    bool parseWRITE();

    bool parseASSIGN();

    bool parseEXP();

    bool parseT();

    bool parseF();
};
