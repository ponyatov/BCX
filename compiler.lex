%{
#include "compiler.hpp"
%}

%option noyywrap yylineno

%%
[\#\\][^\n]*		{ }						// line comment

nop					{ yylval.op = op_NOP; return CMD0; }
bye					{ yylval.op = op_BYE; return CMD0; }

\.vm				{ return pVM; }
\.end				{ return pEND; }

\.save				{ return pSAVE; }
[a-zA-Z0-9_]+\.bc	{ yylval.s = new std::string(yytext); return FILENAME; }

\:					{ return COLON; }
[a-zA-Z0-9_]+		{ yylval.s = new std::string(yytext); return SYMBOL; }

[ \t\r\n]+			{}						// drop spaces
.					{ yyerror("lexer");	}	// undetected char

