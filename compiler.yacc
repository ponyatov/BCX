%{
#include "compiler.hpp"
%}

%defines %union { uint8_t op; std::string *s; CELL n; }

%token pEND pVM pSAVE
%token <s>  FILENAME
%token <op> CMD0 CMD1
%token COLON
%token <s>  SYMBOL
%token <n>	NUMBER

%%
REPL :
REPL : REPL pVM				{            Lunresolved(); BCX();   }
REPL : REPL pEND			{ DUMP();    Lunresolved(); exit(0); }
REPL : REPL pSAVE FILENAME	{ save(*$3); Lunresolved(); exit(0); }
REPL : REPL CMD0			{ Bcompile($2); }
REPL : REPL SYMBOL COLON	{ Ldefine($2); }
REPL : REPL CMD1 SYMBOL		{ Bcompile($2); Lcompile($3); } 
REPL : REPL CMD1 NUMBER		{ Bcompile($2);  compile($3); }

