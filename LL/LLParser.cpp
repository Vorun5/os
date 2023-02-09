#include "LLParser.h"

#include <iostream>

#include "Formatter.h"

using namespace std;

void LLParser::parse(const string& input)
{
    m_tokens = lexer(input);
    if (parsePROG() && m_index == m_tokens.size())
    {
        cout << "Program is syntactically correct." << endl;
    }
    else
    {
        cout << "Program is syntactically incorrect." << endl;
    }
    cout << m_index << endl;
}

vector<Token> LLParser::lexer(string program)
{
    for (size_t i = 0; i < program.length(); i++)
    {
        switch (const char c = program[i])
        {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            break;
        case '+':
            m_tokens.push_back({PLUS, "+"});
            break;
        case '-':
            m_tokens.push_back({MINUS, "-"});
            break;
        case '*':
            m_tokens.push_back({MULTIPLY, "*"});
            break;
        case '(':
            m_tokens.push_back({LPAREN, "("});
            break;
        case ')':
            m_tokens.push_back({RPAREN, ")"});
            break;
        case ';':
            m_tokens.push_back({SEMICOLON, ";"});
            break;
        case ':':
            {
                if (i + 1 < program.length() && program[i + 1] == '=')
                {
                    m_tokens.push_back({ASSIGN, ":="});
                    i++;
                    break;
                }
                m_tokens.push_back({COLON, ":"});
                break;
            }
        case ',':
            m_tokens.push_back({COMMA, ","});
            break;
        default:
            if (isalpha(c))
            {
                string id;
                id += c;
                while (isalpha(program[++i]) || isdigit(program[i]))
                    id += program[i];
                --i;
                for (size_t j = 0; j < id.length(); j++)
                    id[j] = tolower(id[j]);

                if (id == "prog")
                    m_tokens.push_back({PROG, "PROG"});
                else if (id == "var")
                    m_tokens.push_back({VAR, "VAR"});
                else if (id == "begin")
                    m_tokens.push_back({BEGIN, "BEGIN"});
                else if (id == "end")
                    m_tokens.push_back({END, "END"});
                else if (id == "read")
                    m_tokens.push_back({READ, "READ"});
                else if (id == "write")
                    m_tokens.push_back({WRITE, "WRITE"});
                else if (id == "int")
                    m_tokens.push_back({INT, "INT"});
                else if (id == "float")
                    m_tokens.push_back({FLOAT, "FLOAT"});
                else if (id == "bool")
                    m_tokens.push_back({BOOL, "BOOL"});
                else if (id == "string")
                    m_tokens.push_back({STRING, "STRING"});
                else if (id == "id")
                    m_tokens.push_back({ID, "ID"});
                else if (id == "num")
                    m_tokens.push_back({NUM, "NUM"});
                else
                    throw std::runtime_error(Formatter() << "Unexpected word at " << i << " positions!");
            }
            else
                throw std::runtime_error(Formatter() << "Unexpected symbol at " << i << " positions!");
            break;
        }
    }
    return m_tokens;
}

bool LLParser::match(TokenType expected)
{
    if (m_tokens[m_index].type == expected)
    {
        m_index++;
        return true;
    }
    return false;
}

bool LLParser::parsePROG()
{
    if (!match(PROG))
    {
        return false;
    }
    if (!match(ID))
    {
        return false;
    }
    if (!parseVAR())
    {
        return false;
    }
    if (!match(BEGIN))
    {
        return false;
    }
    if (!parseLISTST())
    {
        return false;
    }
    if (!match(END))
    {
        return false;
    }
    return true;
}

bool LLParser::parseVAR()
{
    if (!match(VAR))
    {
        return false;
    }
    if (!parseIDLIST())
    {
        return false;
    }
    if (!match(COLON))
    {
        return false;
    }
    if (!parseTYPE())
    {
        return false;
    }
    if (!match(SEMICOLON))
    {
        return false;
    }
    return true;
}

bool LLParser::parseIDLIST()
{
    if (!match(ID))
    {
        return false;
    }
    while (match(COMMA))
    {
        if (!match(ID))
        {
            return false;
        }
    }
    return true;
}

bool LLParser::parseLISTST()
{
    if (!parseST())
    {
        return false;
    }
    while (parseST())
    {
    }
    return true;
}

bool LLParser::parseTYPE()
{
    return match(INT) ||
        match(FLOAT) ||
        match(BOOL) ||
        match(STRING);
}

bool LLParser::parseST()
{
    return parseREAD() ||
        parseWRITE() ||
        parseASSIGN();
}

bool LLParser::parseREAD()
{
    if (!match(READ))
        return false;
    if (!match(LPAREN))
        return false;
    if (!parseIDLIST())
        return false;
    if (!match(RPAREN))
        return false;
    if (!match(SEMICOLON))
        return false;
    return true;
}

bool LLParser::parseWRITE()
{
    if (!match(WRITE))
        return false;
    if (!match(LPAREN))
        return false;
    if (!parseIDLIST())
        return false;
    if (!match(RPAREN))
        return false;
    if (!match(SEMICOLON))
        return false;
    return true;
}

bool LLParser::parseASSIGN()
{
    if (!match(ID))
        return false;
    if (!match(ASSIGN))
        return false;
    if (!parseEXP())
        return false;
    if (!match(SEMICOLON))
        return false;
    return true;
}

bool LLParser::parseEXP()
{
    if (!parseT())
        return false;
    while (match(PLUS))
        if (!parseT())
            return false;
    return true;
}

bool LLParser::parseT()
{
    if (!parseF())
        return false;
    while (match(MULTIPLY))
        if (!parseF())
            return false;
    return true;
}

bool LLParser::parseF()
{
    if (match(MINUS))
    {
        if (!parseF())
            return false;
        return true;
    }
    if (match(LPAREN))
    {
        if (!parseEXP())
            return false;
        if (!match(RPAREN))
            return false;
        return true;
    }
    if (match(ID) || match(NUM))
    {
        m_index++;
        return true;
    }
    return false;
}
