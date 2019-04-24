#include "bcx.h"

uint8_t M[Msz];   UCELL Ip =0; uint8_t op =0;
			      UCELL Cp =0;
  UCELL R[Rsz]; uint8_t Rp =0;
   CELL D[Dsz]; uint8_t Dp =0;

void BCX(void) {
	for (;;) {
		op = M[Ip++];
		printf("\n%.4X: %.2X ",Ip-1,op);
		switch (op) {
			case op_NOP: NOP(); break;
			case op_BYE: BYE(); break;
			default: abort();
		}
	}
}

extern CELL POP(void) { return D[Dp--]; }

extern CELL TOP(void) { return D[Dp]; }

void NOP(void)	{ printf("nop"); }
void BYE(void)  { printf("bye\n\n"); exit(POP()); }
void DUMP(void) { printf("\n\n%.4X[%.4X]\n\n",POP(),POP()); }
