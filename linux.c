#include "linux.h"

#ifndef BCXCOMPILER

int main(int argc, char* argv[]) {
	assert(argc==2);
	for (int i=0;i<argc;i++) printf("\nargv[%i]=%s",i,argv[i]);
	FILE *bc = fopen(argv[1],"rb"); assert(bc);
	Cp = fread(M,1,Msz,bc); assert(Cp>0);
	fclose(bc);
	BCX();
//	return 0;
}

#endif // BCXCOMPILER

