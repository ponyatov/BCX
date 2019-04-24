#include "bcx.h"

/* для IAR используйте утилиту bc2c и задайте define в настройках проекта */
#ifndef BCXIAR
BYTE M[Msz]; UCELL Cp =0;
#endif

   UCELL Ip =0; uint8_t op =0;
  UCELL R[Rsz]; uint8_t Rp =0;
   CELL D[Dsz]; uint8_t Dp =0;

void BCX(void) {
	for (;;) {
		op = M[Ip++];
		printf("\n%.4X: %.2X ",Ip-1,op);
		switch (op) {
			case op_NOP:  NOP();  break;
			case op_BYE:  BYE();  break;
			case op_JMP:  JMP();  break;
			case op_qJMP: qJMP(); break;
			case op_CALL: CALL(); break;
			case op_RET:  RET();  break;
			default: abort();
		}
	}
}

extern CELL POP(void) { return D[Dp--]; }

extern CELL TOP(void) { return D[Dp]; }

void NOP(void)	{ printf("nop"); }
void BYE(void)  { printf("bye\n\n"); exit(POP()); }
void DUMP(void) { printf("\n\n%.4X[%.4X]\n\n",POP(),POP()); }

void store(UCELL addr, CELL cell) { M[addr+0] = cell; M[addr+1] = cell>>8; }
CELL fetch(UCELL addr) 			  { return M[addr+1]<<8|M[addr+0]; }

void Bcompile(uint8_t byte) { M[Cp++] = byte; }
void compile(CELL cell) { store(Cp,cell); Cp += CELLsz; }

void JMP(void)  { Ip = fetch(Ip); printf("jmp\t%.4X",Ip); }
void qJMP(void) { printf("?jmp\t"); if (POP()==0) { Ip = fetch(Ip); printf("%.4X",Ip); } }
void CALL(void) { R[Rp++] = Ip; Ip = fetch(Ip); printf("call\t%.4X",Ip); }
void RET(void)  { printf("ret"); Ip=R[--Rp]; }
