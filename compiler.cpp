#include "compiler.hpp"

#define YYERR "\n\n"<< yylineno <<':'<< msg <<"["<< yytext <<"]\n\n"
void yyerror(std::string msg) { std::cout<<YYERR; std::cerr<<YYERR; exit(-1); }

#ifdef BCXCOMPILER

int main(int argc, char* argv[]) {
	assert(argc==2);
	yyin = fopen( argv[1], "r" ); if (!yyin) abort();
	return yyparse();
}

void save(char *filename) {
	FILE *bc = fopen(filename,"wb");
	fwrite(M,Cp,1,bc);
	fclose(bc);
}

#endif // BCXCOMPILER

