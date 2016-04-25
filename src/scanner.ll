/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include <stdio.h>
#include "scanner.hpp"

/* import the parser's token type into a local typedef */
typedef example::Parser::token token;
typedef example::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::TOKEN_END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
%}

/*** Flex Declarations and Options ***/
%option debug batch
/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ExampleFlexLexer" */
%option prefix="Example"

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */


 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

"%".* {
    yylloc->step();
}

"FORW" {
    return token::TOKEN_FORW;
}

"BACK" {
    return token::TOKEN_BACK;
}

"UP" {
    return token::TOKEN_UP;
}

"DOWN" {
    return token::TOKEN_DOWN;
}

"LEFT" {
    return token::TOKEN_LEFT;
}

"RIGHT" {
    return token::TOKEN_RIGHT;
}

"COLOR" {
    return token::TOKEN_COLOR;
}

"REP" {
    return token::TOKEN_REP;
}

"\"" {
    return token::TOKEN_QUOTE;
}

"#"[0-9A-F]{6} {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::TOKEN_HEX;
}

"+" {
    return token::TOKEN_PLUS;
}

"-" {
    return token::TOKEN_MINUS;
}

"*" {
    return token::TOKEN_MUL;
}

"/" {
    return token::TOKEN_DIV;
}

"=" {
    return token::TOKEN_EQ;
}

"(" {
    return token::TOKEN_LPAR;
}

")" {
    return token::TOKEN_RPAR;
}

"." {
    return token::TOKEN_DOT;
}

[0-9]+ {
    yylval->integerVal = atoi(yytext);
    return token::TOKEN_INTEGER;
}

[A-Z][A-Z0-9_]* {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::TOKEN_STRING;
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); 
    yylloc->step();
}
 /* gobble up white-spaces */
[ \t\r]+ {
    yylloc->step();
}

. {
    return static_cast<token_type>(*yytext);
}

%% /*** Additional Code ***/

namespace example {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : ExampleFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int ExampleFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int ExampleFlexLexer::yywrap()
{
    return 1;
}
