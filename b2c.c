// convert .bc bytecode to .c source code (microcontroller include)

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bcx.h"

int main(int argc, char*argv[]) {
	assert(argc==3);
	FILE *in = fopen(argv[1],"rb");
	FILE *out = fopen(argv[2],"wb");

	Cp = fread(M,1,Msz,in); assert(Cp);

	fprintf(out,"#include \"bcx.h\"\r\n\r\n#ifdef BCX2C\r\n\r\n");
	fprintf(out,"BYTE M[Msz]={");

	for (UCELL addr = 0; addr < Cp; addr++) {
		if (!(addr % 8)) fprintf(out,"\r\n\t");
		fprintf(out,"0x%.2X,",M[addr]);
	}

	fprintf(out,"\r\n0};\r\n\r\nUCELL Cp =0x%.4X;\r\n\r\n#endif\r\n\r\n",Cp);
	return 0;
}

