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
 * @defgroup bmxvm vm
 * @brief ����������� ������
 * @{
*/

                                                        /** @brief ����� ������ �� */
#define  CELL   int16_t
                                                        /** @brief ����������� CELl */
#define UCELL  uint16_t
                                                        /** @rief ������ @ref CELL � ������ */
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
extern uint8_t M[Msz];
                                /** @brief ��������� ���������� */
extern UCELL Ip;
								/** @bried current opcode */
extern uint8_t op;
                                /** @brief ��������� ����������/��������� ������ */
extern UCELL Cp;
                                /** @brief ���� ��������� */
extern UCELL R[Rsz];
                                /** @brief ������� ����� ��������� */
extern uint8_t Rp;

                                /** @brief ���� ������ */
extern CELL D[Dsz];
                                /** @brief ������� ����� ������ */
extern uint8_t Dp;

                                /** @brief ����� ������� ����� */
extern CELL POP(void);
                                /** @brief �������� ������� ����� */
extern CELL TOP(void);

							/** @brief ������������� �������� */
extern void BCX(void);

/** @} */

							/** @name ������ */

							/** @brief `NOP ( -- )` ������ ������� */
#define op_NOP  0x00
#define op_BYE  0xFF
#define op_JMP  0x01
#define op_qJMP 0x02
#define op_CALL 0x03
#define op_RET  0x04
#define op_LIT  0x05

/**
 * @defgroup debug debug
 * @brief �������
 * @{
 * */
                            /// `DUMP ( addr size -- )` ���� ������
extern void DUMP(void);
							/// `NOP ( -- )` do nothing
extern void NOP(void);
                            /// `BYE ( retcode -- )` ���������� ������
extern void BYE(void);

// @}

// @}

#endif // _H_BCX
