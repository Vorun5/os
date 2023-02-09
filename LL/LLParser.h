﻿#pragma once
#include <vector>
#include "Token.h"

using namespace std;

class LLParser
{
public:
    explicit LLParser()
        : m_index(0),
          m_position(0)
    {
    }

    void parse(const string& input);

private:
    size_t m_index;
    size_t m_position;
    vector<Token> m_tokens;

    vector<Token> lexer(string program);

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