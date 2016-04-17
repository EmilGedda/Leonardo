/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "expression.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "3.0.4"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix "example"

/* set the parser's class identifier */
%define "parser_class_name" {Parser}

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
    int                 integerVal;
    std::string*		stringVal;
    class ArithNode*	node;
}

%define api.token.prefix {TOKEN_}

%token			    END	     0	"end of file"
%token			    EOL		    "end of line"
%token <integerVal> INTEGER		"integer"
%token <stringVal>  STRING		"string"
%token LPAR         "left parenthesis"
%token RPAR         "right parenthesis"
%token DOT          "dot"
%token EQ           "equal sign"
%token PLUS         "plus"
%token MINUS        "minus"
%token MUL          "multiplication"
%token DIV          "division"

%type <node>	constant variable
%type <node>	atomexpr unaryexpr mulexpr addexpr expr

%destructor { delete $$; } STRING
%destructor { delete $$; } constant variable
%destructor { delete $$; } atomexpr unaryexpr mulexpr addexpr expr

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN EXAMPLE - Change the example grammar rules below ***/

constant: INTEGER
        {
	       $$ = new NConstant($1);
	    }

variable: STRING
        {
	        if (!driver.calc.existsVariable(*$1)) {
		        error(yyla.location, std::string("Unknown variable \"") + *$1 + "\"");
		        delete $1;
		        YYERROR;
	        } else {
		        $$ = new NConstant( driver.calc.getVariable(*$1) );
		        delete $1;
	        }
	    }

atomexpr: constant
        {
	        $$ = $1;
	    }
        | variable
        {
	        $$ = $1;
	    }
        | LPAR expr RPAR
        {
	        $$ = $2;
	    }

unaryexpr: atomexpr
        {
		    $$ = $1;
	    }
        | PLUS atomexpr
        {
		    $$ = $2;
	    }
        | MINUS atomexpr
        {
		    $$ = new NNegate($2);
	    }

mulexpr: unaryexpr
        {
	        $$ = $1;
	    }
        | mulexpr MUL unaryexpr
        {
	        $$ = new NMultiply($1, $3);
	    }
        | mulexpr DIV unaryexpr
        {
	        $$ = new NDivide($1, $3);
	    }

addexpr: mulexpr
        {
	        $$ = $1;
	    }
        | addexpr PLUS mulexpr
        {
	        $$ = new NAdd($1, $3);
	    }
        | addexpr MINUS mulexpr
        {
	        $$ = new NSubtract($1, $3);
	    }

expr: addexpr 
        {
	        $$ = $1;
	    }

assignment: STRING EQ expr DOT
        {
		    driver.calc.variables[*$1] = $3->evaluate();
		    std::cout << "Setting variable " << *$1
			   << " = " << driver.calc.variables[*$1] << "\n";
		    delete $1;
		    delete $3;
	    }

start: /* empty file is valid aswell */
	    | start assignment
        | start expr DOT
        {
	      driver.calc.expressions.push_back($2);
	    }
        
 /*** END EXAMPLE - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
