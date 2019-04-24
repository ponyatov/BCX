#ifndef _H_COMPILER
#define _H_COMPILER

#include "bcx.h"
#include <assert.h>

#include <iostream>

#include <map>
#include <vector>

/**
 * @defgroup excompiler compiler
 * @brief внешний компилятор байткода
 * @ingroup bcx
 * @{
 * */

                                        /// @brief таблица существующих меток
extern std::map<std::string,CELL> label;
                                        /// таблица адресов -- сыылок вперед
extern std::map<std::string,std::vector<CELL>> forward;

					/// определить метку
extern void Ldefine(std::string name);

                                        /// сохранить байткод @ref M\[0..@ref Cp\]
extern void save(std::string filename);

/** @defgroup lexyacc lex/yacc interface 
 * @{ */

					/// олучить следущий токен от лексера
extern int yylex();
					/// текущий номер строки в файле исходного кода
extern int yylineno;
					/// последняя найденна лексером строка
extern char *yytext;
					/// текущий входной файл лексера
extern FILE *yyin;
					/// запуск парсера синтаксиса
extern int yyparse();
					/// callback синтаксической ошибки
extern void yyerror(std::string msg);
#include "parser.hpp"

/// @}

/// @}

#endif // _H_COMPILER

