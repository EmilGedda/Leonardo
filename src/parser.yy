/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "expressions/expression.hpp"
#include "expressions/statement/stassignment.hpp"
#include "expressions/statement/stforw.hpp"
#include "expressions/statement/stpen.hpp"
#include "expressions/statement/stleft.hpp"
#include "expressions/statement/stcolor.hpp"
#include "expressions/statement/strep.hpp"

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


%union {
    int                 integerVal;
    std::string*		stringVal;
    class ArithNode*	node;
    class Statement*    statement;
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

/* Turtle commands */
%token FORW         "forward"
%token BACK         "back"
%token UP           "up"
%token DOWN         "down"
%token LEFT         "left"
%token RIGHT        "right"
%token COLOR        "color"
%token REP          "rep"
%token QUOTE        "\""

%token <stringVal>  HEX "hexcode"

%type <statement> stmt
%type <node>	constant variable
%type <node>	atomexpr unaryexpr mulexpr addexpr expr

%destructor { delete $$; } STRING HEX
%destructor { delete $$; } constant variable
%destructor { delete $$; } atomexpr unaryexpr mulexpr addexpr expr

%{

#include "driver.hpp"
#include "scanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

constant: INTEGER
        {
	        $$ = new NConstant($1);
	    }

variable: STRING
        {
            $$ = new NVariable(*$1, driver.ctx);
            delete $1;
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

stmt: REP expr 
        {
            driver.ctx.ast.push(new AST());
        } repcont
        {
            auto s = driver.ctx.ast.top();
            driver.ctx.ast.pop();
            $$ = new STRep($2, s);
        }
        | FORW expr DOT
        {
            $$ = new STForw($2);
        }
        | BACK expr DOT
        {
            $$ = new STForw(new NNegate($2));
        }
        | DOWN DOT
        {
            $$ = new STPen(1);
        }
        | UP DOT
        {
            $$ = new STPen(0);
        }
        | LEFT expr DOT
        {
            $$ = new STLeft($2);
        }
        | RIGHT expr DOT
        {
            $$ = new STLeft(new NNegate($2));
        }
        | COLOR HEX DOT
        {
            $$ = new STColor(*$2);
            delete $2;
        }
        | STRING EQ expr DOT
        {
            /* SEGFAULT SWAMP */
            std::unique_ptr<ArithNode> node($3);
            $$ = new STAssignment(*$1, std::move(node));
            delete $1; /* Possible?  */
            /* TODO: Fix mem-leak */
	    }

repcont: QUOTE start QUOTE
        {
        
        }
        | stmt 
        {
            driver.ctx.ast.top()->add($1);
        }

start: /* empty file is valid aswell */
        | start stmt
        {
	        driver.ctx.ast.top()->add($2);
	    }
        
 /*** END EXAMPLE - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
