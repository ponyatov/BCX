#include "compiler.hpp"

#define YYERR "\n\n"<< yylineno <<':'<< msg <<"["<< yytext <<"]\n\n"
void yyerror(std::string msg) { std::cout<<YYERR; std::cerr<<YYERR; exit(-1); }

#ifdef BCXCOMPILER

int main(int argc, char* argv[]) {
	assert(argc==2);
	yyin = fopen( argv[1], "r" ); if (!yyin) abort();
	return yyparse();
}

void save(std::string filename) {
	FILE *bc = fopen(filename.c_str(),"wb");
	fwrite(M,1,Cp,bc);
	fclose(bc);
}

std::map<std::string,UCELL> label;
std::map<std::string,std::vector<UCELL>> forward;

void Ldefine(std::string *name) {
	label[*name] = Cp;                              // ���������������� ����� �����
	printf("%.4X:\t%s\n",Cp,name->c_str());		// ������� �����: <addr>: <label>
	auto fw = forward.find(*name);			// ��������� ������ ������
	if ( fw != forward.end() ) {
		for (auto it = fw->second.begin(); it != fw->second.end(); it++ )
			store(*it,Cp);
		forward.erase(fw);			// ������� ������������ �����
	}
}

void Lcompile(std::string *name) {
	if (label.find(*name) != label.end()) {		// ���� ����� ��������
		compile(label[*name]);			// �������������� ��
	} else {

	if (forward.find(*name) == forward.end())	// ���� ��� ��� � forward[]
		forward[*name] = std::vector<UCELL>();	// ������� ������ ������ �������
	forward[*name].push_back(Cp);			// ���������������� ������� Cp
	compile(-1);					// �������������� ��������� �����

	}
}

void Lunresolved(void) {
	for (auto fw = forward.begin(); fw != forward.end(); fw++) {
		std::cerr << "\nUnresolved symbols: ";
		std::cerr << fw->first << "\t";
		std::cerr << "\n\n"; 
		abort();
	}
}


#endif // BCXCOMPILER

