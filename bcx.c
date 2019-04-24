#include "bcx.h"

CELL M[Msz];  UCELL Ip=0;
UCELL Cp=0;
UCELL R[Rsz]; uint8_t Rp=0;
 CELL D[Dsz]; uint8_t Dp=0;

void BCX(void) {
}

extern CELL POP(void) { return D[Dp--]; }

extern CELL TOP(void) { return D[Dp]; }

void BYE(void)  { exit(POP()); }
void DUMP(void) { printf("\n\n%.4X[%.4X]\n\n",POP(),POP()); }
