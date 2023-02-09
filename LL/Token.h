#pragma once
#include <string>
#include <map>

using namespace std;

enum TokenType
{   PROG,   VAR,    BEGIN,  END,    READ,   WRITE,  ID,
    INT,    FLOAT,  BOOL,   STRING, ASSIGN, PLUS,
    MULTIPLY,   LPAREN, RPAREN, SEMICOLON,  NUM,
    COLON,  COMMA, MINUS,
};

const map<TokenType, string> tokenTypeMap = {
    {PROG, "PROG"},
    {VAR, "VAR"},
    {BEGIN, "BEGIN"},
    {END, "END"},
    {STRING, "STRING"},
    {READ, "READ"},
    {WRITE, "WRITE"},
    {ID, "ID"},
    {INT, "INT"},
    {FLOAT, "FLOAT"},
    {BOOL, "BOOL"},
    {STRING, "STRING"},
    {ASSIGN, ":="},
    {PLUS, "+"},
    {MULTIPLY, "*"},
    {LPAREN, "("},
    {RPAREN, ")"},
    {SEMICOLON, ";"},
    {NUM, "NUM"},
    {COLON, ":"},
    {COMMA, ","},
    {MINUS, "-"},
};

struct Token
{
    TokenType type;
    string value;
};
