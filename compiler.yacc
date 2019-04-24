%{
#include "compiler.hpp"
%}

%defines %union { uint8_t op; std::string *s; }

%token pEND pVM pSAVE
%token <s>  FILENAME
%token <op> CMD0 CMD1
%token COLON
%token <s>  SYMBOL

%%
REPL :
REPL : REPL pVM				{ BCX(); }
REPL : REPL pEND			{ DUMP(); BYE(); }
REPL : REPL pSAVE FILENAME	{ save(*$3); BYE(); }
REPL : REPL CMD0			{ M[Cp++] = $2; }
REPL : REPL SYMBOL COLON	{ Ldefine(*$2); }


