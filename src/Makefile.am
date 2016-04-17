# $Id$

AM_CFLAGS = -W -Wall -Wextra -ansi
AM_CXXFLAGS = -W -Wall -Wextra -ansi

noinst_LIBRARIES = liblogoparser.a

liblogoparser_a_SOURCES = \
	parser.yy scanner.ll parser.h scanner.h y.tab.h \
	location.hh position.hh stack.hh FlexLexer.h \
	driver.cc driver.h expression.h

bin_PROGRAMS = leonardo

leonardo_SOURCES = exprtest.cc
leonardo_DEPENDENCIES = liblogoparser.a

LIBS = liblogoparser.a

# this output override is needed because the c++ scanner is outputted into
# lex.yy.cc and the automake ylwrap script only checks for lex.yy.c
AM_LFLAGS = -olex.yy.c

extraclean:
	rm -f parser.cc parser.h scanner.cc

rebuild: clean extraclean all
