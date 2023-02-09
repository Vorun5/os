#pragma once
#include <string>

using namespace std;

enum TokenType
{
    PROG,
    // PROG
    VAR,
    // VAR
    BEGIN,
    // BEGIN
    END,
    // END
    READ,
    // READ
    WRITE,
    // WRITE
    ID,
    // id
    INT,
    // INT
    FLOAT,
    // FLOAT
    BOOL,
    // BOOL
    STRING,
    // STRING
    ASSIGN,
    // :=
    PLUS,
    // +
    MINUS,
    // -
    MULTIPLY,
    // *
    LPAREN,
    // (
    RPAREN,
    // )
    SEMICOLON,
    // ;
    NUM,
    // num
    COLON,
    // :
    COMMA,
    // ,
};

struct Token
{
    TokenType type;
    string value;
};
