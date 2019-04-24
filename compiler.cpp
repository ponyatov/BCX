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
	fwrite(M,1,Cp,bc);
	fclose(bc);
}

std::map<std::string,CELL> label;
std::map<std::string,std::vector<CELL>> forward;

void Ldefine(char name[]) {
	label[std::string(name)] = Cp;							// register new label
	printf("%.4X:\t%s\n",Cp,name);		// dump symbol table
	for (auto i=label.begin(),e=label.end();i!=e;i++) {
		std::cout << "<"<< i->first << ">\n";
	}
//	auto fw = forward.find(*name);				// resolve forward references
//	if ( fw != forward.end() )
//		for (auto it = fw->second.begin(); it != fw->second.end(); it++ )
//			store(*it,Cp);
}

#endif // BCXCOMPILER

