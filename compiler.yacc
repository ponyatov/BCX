%{
#include "compiler.hpp"
%}

%defines %union { uint8_t op; char *s; }

%token pEND pVM pSAVE
%token <s>  FILENAME
%token <op> CMD0

%%
REPL :
REPL : REPL pVM				{ BCX(); }
REPL : REPL pEND			{ DUMP(); BYE(); }
REPL : REPL pSAVE FILENAME	{ save($3); BYE(); }
REPL : REPL CMD0			{ M[Cp++] = $2; }

