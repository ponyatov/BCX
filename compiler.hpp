#ifndef _H_COMPILER
#define _H_COMPILER

/**
 * @file
 * @brief внешний компилятор байткода (C++/flex/bison)
 */

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

/// @brief таблица существующих меток (имя метки: адрес)
extern std::map<std::string,UCELL> label;
/// @brief таблица ссылок вперед (имя метки: список адресов параметров команд `jmp`/`call`)
/// @details при каждом определении новой метки в Ldefine()
extern std::map<std::string,std::vector<UCELL>> forward;

					/// определить метку с текущим @ref Cp
extern void Ldefine(std::string *name);
                                        /// скомпилировать метку по имени
extern void Lcompile(std::string *name);
										/// dump unresolved and abort
extern void Lunresolved(void);

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

