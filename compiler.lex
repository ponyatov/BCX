%{
#include "compiler.hpp"
%}

%option noyywrap yylineno

%%
[\#\\][^\n]*		{ }						// line comment

nop					{ yylval.op = op_NOP;  return CMD0; }
bye					{ yylval.op = op_BYE;  return CMD0; }

jmp					{ yylval.op = op_JMP;  return CMD1; }
\?jmp				{ yylval.op = op_qJMP; return CMD1; }
call				{ yylval.op = op_CALL; return CMD1; }
ret					{ yylval.op = op_RET;  return CMD0; }
lit					{ yylval.op = op_LIT;  return CMD1; }

\.vm				{ return pVM; }
\.end				{ return pEND; }

\.save				{ return pSAVE; }
[a-zA-Z0-9_]+\.bc	{ yylval.s = new std::string(yytext); return FILENAME; }

0x[0-9a-fA-F]+		{ yylval.n = strtol(&yytext[2],NULL,0x10); return NUMBER; }
0b[01]+				{ yylval.n = strtol(&yytext[2],NULL,0x02); return NUMBER; }

\:					{ return COLON; }
[a-zA-Z0-9_]+		{ yylval.s = new std::string(yytext); return SYMBOL; }


[ \t\r\n]+			{ }						// drop spaces
.					{ yyerror("lexer");	}	// undetected char

