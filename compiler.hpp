#ifndef _H_COMPILER
#define _H_COMPILER

#include "bcx.h"
#include <assert.h>

#include <iostream>

#include <map>
#include <vector>

/**
 * @defgroup excompiler compiler
 * @brief ������� ���������� ��������
 * @ingroup bcx
 * @{
 * */

                                        /// @brief ������� ������������ �����
extern std::map<std::string,CELL> label;
                                        /// ������� ������� -- ������ ������
extern std::map<std::string,std::vector<CELL>> forward;

					/// ���������� �����
extern void Ldefine(std::string name);

                                        /// ��������� ������� @ref M\[0..@ref Cp\]
extern void save(std::string filename);

/** @defgroup lexyacc lex/yacc interface 
 * @{ */

					/// ������� �������� ����� �� �������
extern int yylex();
					/// ������� ����� ������ � ����� ��������� ����
extern int yylineno;
					/// ��������� �������� �������� ������
extern char *yytext;
					/// ������� ������� ���� �������
extern FILE *yyin;
					/// ������ ������� ����������
extern int yyparse();
					/// callback �������������� ������
extern void yyerror(std::string msg);
#include "parser.hpp"

/// @}

/// @}

#endif // _H_COMPILER

