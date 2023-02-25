#pragma once

enum class Token
{
    Identifier,
    If, // if
    Else, // else
    Do, // do
    While, // while
    For, // for
    Int, // int
    Double, // double
    Bool, // bool
    IntegerNumericLiteral, // -123
    FloatingPointNumberLiteral, // -32.14
    Plus, // +
    Minus, // -
    Asterisk, // *
    Slash, // /
    Assignment, // =
    Less, // <
    Greater, // >
    Equal, // ==
    NotEqual, // !=
    LessEqual, // <=
    GreaterEqual, // >=
    Comma, // ,
    Dot, // .
    Colon, // :
    Semicolon, // ;
    LeftParenthesis, // (
    RightParenthesis, // )
    OpeningCurlyBrace, // {
    ClosingCurlyBrace, // }
    OpeningSquareBrace, // [
    ClosingSquareBrace, // ]
    DoubleColon, // ::
    RightArrow,  // ->
    CommentOpening, // /*
    CommentEnding, // */
    Error,
};
