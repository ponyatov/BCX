/** @file 
 * @brief `bcx:FORTH`
 * */

/**
 * @defgroup bcx bcx:FORTH
 * @brief ������������� �������� ��� ������������ ������ @ref bcxmd
 * @{
 * */

#ifndef _H_BCX
#define _H_BCX

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

/**
 * @defgroup bcxvm vm
 * @brief ����������� ������
 * @{
*/
                                /** @brief ���� */
#define  BYTE   uint8_t
                                /** @brief ����� ������ �� */
#define  CELL   int16_t
                                /** @brief ����������� @ref CELL */
#define UCELL  uint16_t
                                /** @brief ������ @ref CELL � ������ */
#define CELLsz (sizeof(CELL))

/** 
 * @defgroup bcxconfig ������������
 * @{
 * */

                                /** @brief ������ ������ �� � ������ */
#define Msz 0x1000
                                /** @brief ������ ����� ��������� */
#define Rsz 0x100
                                /** @brief ������ ����� ������ */
#define Dsz 0x10

/** @} */

                                /** @brief ������ �� (�������������) */
extern BYTE M[Msz];
                                /** @brief ��������� ���������� */
extern UCELL Ip;
			        /** @brief ����� ������� ������� */
extern BYTE op;
                                /** @brief ��������� ����������/��������� ������ */
extern UCELL Cp;
                                /** @brief ���� ��������� */
extern UCELL R[Rsz];
                                /** @brief ������� ����� ��������� */
extern BYTE Rp;

                                /** @brief ���� ������ */
extern CELL D[Dsz];
                                /** @brief ������� ����� ������ */
extern BYTE Dp;

                                /** @brief ����� ������� ����� */
extern CELL POP(void);
                                /** @brief �������� ������� ����� */
extern CELL TOP(void);

							/** @brief ������������� �������� */
extern void BCX(void);

/** 
 * @defgroup bcxcmd �������
 * @{ */

/**
 * @defgroup bcxop ������� �������
 * @{ */

			    /** @brief `NOP ( -- )` ������ ������� */
                            /** @brief `BYE ( retcode -- )` ���������� ������ */
#define op_JMP  0x01
#define op_qJMP 0x02
#define op_CALL 0x03
#define op_RET  0x04
#define op_LIT  0x05

/** @} bcxop */

/**
 * @defgroup bcxcflow ���������� ������� ����������
 * @{ */

			    /** @brief @ref NOP `( -- )` ������ ������� */
#define op_NOP  0x00
extern void NOP(void);
                            /** @brief @ref BYE `( retcode -- )` ���������� ������ */
#define op_BYE  0xFF
extern void BYE(void);

extern void JMP(void);
extern void qJMP(void);
extern void CALL(void);
extern void RET(void);

/** @} bcxcflow */

/**
 * @defgroup debug �������
 * @{
 * */
                            /// @brief `DUMP ( addr size -- )` ���� ������
extern void DUMP(void);

/** @} debug */

/// @} bcxcmd

extern void store(UCELL addr, CELL cell);
extern void Bcompile(uint8_t);
extern void compile(CELL cell);

// @}

#endif // _H_BCX
