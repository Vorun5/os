#include <iostream>
#include "LLParser.h"
#include "Formatter.h"

using namespace std;

void LLParser::parse(const string& input)
{
    m_tokens = lexer(input);
    const bool isValid = parsePROG();
    cout << "Total tokens: " << m_tokens.size() << endl;
    if (isValid && m_index == m_tokens.size())
    {
        cout << "SUCCESS: Program is syntactically correct." << endl;
        return;
    }
    if (isValid && m_index < m_tokens.size())
    {
        cout << "ERROR: Program has " << m_tokens.size() - m_index << " extra tokens!" << endl;
    }
}

vector<Token> LLParser::lexer(const string& program)
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
                string idOriginal = id;
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
                    throw std::runtime_error(
                        Formatter() << "Unexpected word " << idOriginal << " at " << i << " positions!");
            }
            else
                throw std::runtime_error(Formatter() << "Unexpected symbol " << c << " at " << i << " positions!");
            break;
        }
    }
    return m_tokens;
}

void LLParser::Expected(const std::string& expected) const
{
    ErrorLog("Expected " + expected +
        " but received " + m_tokens[m_index].value + "\n       Positions: " + std::to_string(m_index));
}

void LLParser::ErrorLog(const std::string& message) const
{
    throw std::runtime_error(
        Formatter() << "Total tokens: " << m_tokens.size() << "\nERROR: " << message);
}

bool LLParser::match(const TokenType expected)
{
    if (m_index >= m_tokens.size())
    {
        if (const auto it = tokenTypeMap.find(expected); it != tokenTypeMap.end())
        {
            ErrorLog("Expected " + it->second +
                " but received end of program\n       Positions: " + std::to_string(m_index - 1));
        }
        else
        {
            ErrorLog("Unexpected end of program");
        }
    }
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
        Expected("PROG");
        return false;
    }
    if (!match(ID))
    {
        Expected("ID");
        return false;
    }
    if (!parseVAR())
    {
        return false;
    }
    if (!match(BEGIN))
    {
        Expected("BEGIN");
        return false;
    }
    if (m_tokens[m_tokens.size() - 1].type != TokenType::END)
    {
        ErrorLog(
            "The program should end with END, but it ends with " + m_tokens[m_tokens.size() - 1].value +
            " .\n       Positions: " + std::to_string(m_tokens.size()));
    }
    if (!parseLISTST())
    {
        Expected("LISTST");
        return false;
    }
    if (!match(END))
    {
        Expected("END");
        return false;
    }
    return true;
}

bool LLParser::parseVAR()
{
    if (!match(VAR))
    {
        Expected("VAR");
        return false;
    }
    if (!parseIDLIST())
    {
        return false;
    }
    if (!match(COLON))
    {
        Expected(":");
        return false;
    }
    if (!parseTYPE())
    {
        return false;
    }
    if (!match(SEMICOLON))
    {
        Expected(";");
        return false;
    }
    return true;
}

bool LLParser::parseIDLIST()
{
    if (!match(ID))
    {
        Expected("ID");
        return false;
    }
    if (m_index >= m_tokens.size())
    {
        ErrorLog("Expected : but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }
    while (match(COMMA))
    {
        if (!match(ID))
        {
            Expected("ID");
            return false;
        }
    }
    return true;
}

bool LLParser::parseLISTST()
{
    if (!parseST())
    {
        Expected("ST");
        return false;
    }
    if (m_index >= m_tokens.size())
    {
        ErrorLog("Expected END but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }
    while (parseST())
    {
    }
    return true;
}

bool LLParser::parseTYPE()
{
    if (m_index >= m_tokens.size())
    {
        ErrorLog("Expected TYPE but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }

    return match(INT) ||
        match(FLOAT) ||
        match(BOOL) ||
        match(STRING);
}

bool LLParser::parseST()
{
    return parseREAD() || parseWRITE() || parseASSIGN();
}

bool LLParser::parseREAD()
{
    if (!match(READ))
        return false;
    if (!match(LPAREN))
    {
        Expected("(");
        return false;
    }
    if (!parseIDLIST())
        return false;
    if (!match(RPAREN))
    {
        Expected(")");
        return false;
    }
    if (!match(SEMICOLON))
    {
        Expected(";");
        return false;
    }
    return true;
}

bool LLParser::parseWRITE()
{
    if (!match(WRITE))
        return false;
    if (!match(LPAREN))
    {
        Expected("(");
        return false;
    }
    if (!parseIDLIST())
        return false;
    if (!match(RPAREN))
    {
        Expected(")");
        return false;
    }
    if (!match(SEMICOLON))
    {
        Expected(";");
        return false;
    }
    return true;
}

// id := num+id*-num
bool LLParser::parseASSIGN()
{
    if (!match(ID))
    {
        return false;
    }
    if (!match(ASSIGN))
    {
        Expected(":=");
        return false;
    }
    if (m_index >= m_tokens.size())
    {
        ErrorLog("Expected EXP but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }
    if (!parseEXP())
    {
        Expected("EXP");
        return false;
    }
    if (!match(SEMICOLON))
    {
        if (m_tokens[m_index].type == TokenType::MINUS)
        {
            ErrorLog("Expected F or ID or LPAREN but received ;\n       Positions: " + std::to_string(m_index));
        }
        return false;
    }
    return true;
}

// (num+id-num)*((id))
bool LLParser::parseEXP()
{
    if (m_index >= m_tokens.size())
    {
        ErrorLog("Expected EXP but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }
    if (!parseT())
    {
        return false;
    }
    while (match(PLUS))
    {
        if (!parseT())
        {
            return false;
        }
    }
    return true;
}

bool LLParser::parseT()
{
    if (m_index >= m_tokens.size())
    {
        ErrorLog("Expected T but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }
    if (!parseF())
    {
        return false;
    }
    if (m_index >= m_tokens.size())
    {
        ErrorLog(
            "Expected some operator but received end of program\n       Positions: " + std::to_string(m_index - 1));
    }
    while (match(MULTIPLY))
    {
        if (!parseF())
        {
            return false;
        }
    }
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
        {
            Expected("EXP");
            return false;
        }

        if (!match(RPAREN))
        {
            Expected(")");
            return false;
        }

        return true;
    }
    if (match(ID) || match(NUM))
    {
        return true;
    }

    return false;
}
