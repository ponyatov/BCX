#ifndef _H_COMPILER
#define _H_COMPILER

#include "bcx.h"

#include <iostream>

/** @name lex/yacc interface */

										/// fetch next token from lexer
extern int yylex();
										/// current line in source file
extern int yylineno;
										/// last matched string in lexer
extern char *yytext;
										/// run parser
extern int yyparse();
										/// error callback
extern void yyerror(std::string msg);
#include "parser.hpp"

#endif // _H_COMPILER

