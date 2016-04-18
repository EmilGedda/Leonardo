# $Id$

AM_CFLAGS = -W -Wall -Wextra -ansi
AM_CXXFLAGS = -W -Wall -Wextra -std=c++14

noinst_LIBRARIES = liblogoparser.a

liblogoparser_a_SOURCES = \
	parser.yy scanner.ll parser.hpp scanner.hpp y.tab.hpp \
	location.hh position.hh stack.hh FlexLexer.h \
	driver.cpp driver.hpp expression.hpp

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
