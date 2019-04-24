#ifndef _H_COMPILER
#define _H_COMPILER

#include "bcx.h"

#include <iostream>
#include <cassert>

extern void save(char *filename);

/** @name lex/yacc interface */

										/// fetch next token from lexer
extern int yylex();
										/// current line in source file
extern int yylineno;
										/// last matched string in lexer
extern char *yytext;
										/// lexr input file handler
extern FILE *yyin;
										/// run parser
extern int yyparse();
										/// error callback
extern void yyerror(std::string msg);
#include "parser.hpp"

#endif // _H_COMPILER

