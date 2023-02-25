#include <unordered_map>

#include "ContextTokenLogger.h"

static const std::unordered_map<Token, std::string> tokenNames = {
    {Token::Identifier, "Identifier"},
    {Token::If, "Keyword IF"},
    {Token::Else, "Keyword ELSE"},
    {Token::Do, "Keyword DO"},
    {Token::While, "Keyword WHILE"},
    {Token::For, "Keyword FOR"},
    {Token::Int, "Type INT"},
    {Token::Double, "Type DOUBLE"},
    {Token::Bool, "Type BOOL"},
    {Token::IntegerNumericLiteral, "Type INTEGER"},
    {Token::FloatingPointNumberLiteral, "Type FLOAT"},
    {Token::Plus, "Operator PLUS"},
    {Token::Minus, "Operator MINUS"},
    {Token::Asterisk, "Operator ASTERISK"},
    {Token::Slash, "Operator DIVISION"},
    {Token::Assignment, "Operator ASSIGNMENT"},
    {Token::Less, "Logic operator LESS"},
    {Token::Greater, "Logic operator GREATER"},
    {Token::Equal, "Logic operator EQUAL"},
    {Token::NotEqual, "Logic operator  Operator NOT EQUAL"},
    {Token::LessEqual, "Logic operator  LESS EQUAL"},
    {Token::GreaterEqual, "Logic operator GREATER EQUAL"},
    {Token::Comma, "Special symbol COMMA"},
    {Token::Dot, "Special symbol  DOT"},
    {Token::Colon, "Special symbol  COLON"},
    {Token::Semicolon, "Special symbol  SEMICOLON"},
    {Token::LeftParenthesis, "Special symbol  LEFT PARENTHESIS"},
    {Token::RightParenthesis, "Special symbol  RIGHT PARENTHESIS"},
    {Token::OpeningCurlyBrace, "Special symbol  OPENING CURLY BRACE"},
    {Token::ClosingCurlyBrace, "Special symbol  CLOSING CURLY BRACE"},
    {Token::OpeningSquareBrace, "Special symbol  OPENING SQUARE BRACE"},
    {Token::ClosingSquareBrace, "Special symbol  CLOSING SQUARE BRACE"},
    {Token::DoubleColon, "Special symbol  DOUBLE COLON"},
    {Token::RightArrow, "Special symbol  RIGHT ARROW"},
    {Token::CommentOpening, "Special symbol  COMMENT OPENING"},
    {Token::CommentEnding, "Special symbol  COMMENT ENDING"},
    {Token::Error, "ERROR"}
};

void ContextTokenLogger::SetOutputStream(std::ostream& out)
{
    m_out = out;
}

void ContextTokenLogger::Log(const std::vector<ContextToken>& tokens)
{
    for (auto&& token : tokens)
    {
        LogOne(token);
    }
}

void ContextTokenLogger::LogOne(const ContextToken& tokenWithCtx)
{
    m_out.get() << tokenNames.at(*tokenWithCtx.token) << " '" << tokenWithCtx.lexeme << "' "
        << tokenWithCtx.lineNumber << ':' << tokenWithCtx.columnNumber << std::endl;
}