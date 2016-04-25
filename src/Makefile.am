# $Id$

AM_CFLAGS = -W -Wall -Wextra -ansi -Os
AM_CXXFLAGS = -W -Wall -Wextra -std=c++11 -Os

noinst_LIBRARIES = liblogoparser.a

liblogoparser_a_SOURCES = \
	parser.yy scanner.ll parser.hpp scanner.hpp y.tab.h ast.hpp \
	location.hh position.hh stack.hh FlexLexer.h expressions/statement/strep.hpp \
	context.hpp turtle/turtle.cpp  turtle/turtle.hpp expressions/statement/stforw.hpp \
	expressions/statement/stleft.hpp expressions/statement/stpen.hpp \
	expressions/statement/stcolor.hpp expressions/statement/strep.hpp \
	expressions/statement/stassignment.hpp expressions/arithmetic/arithnode.hpp \
	expressions/arithmetic/nadd.hpp expressions/arithmetic/nvariable.hpp \
	expressions/arithmetic/nconstant.hpp expressions/arithmetic/ndivide.hpp \
	expressions/arithmetic/nmultiply.hpp expressions/arithmetic/nnegate.hpp \
	expressions/arithmetic/nsubtract.hpp expressions/statement/statement.hpp \ 
	driver.cpp driver.hpp expressions/expression.hpp writer.hpp writers/svg.cpp writers/svg.hpp

bin_PROGRAMS = leonardo

leonardo_SOURCES = main.cpp
leonardo_DEPENDENCIES = liblogoparser.a

LIBS = liblogoparser.a

# this output override is needed because the c++ scanner is outputted into
# lex.yy.cc and the automake ylwrap script only checks for lex.yy.c
AM_LFLAGS = -olex.yy.c

extraclean:
	rm -f parser.cc parser.hpp scanner.cc

rebuild: clean extraclean all
