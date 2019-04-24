/** @file 
 * @brief `bcx:FORTH`
 * */

/**
 * @defgroup bcx bcx:FORTH
 * @brief интерпретатор байткода для встраиваемых систем @ref bcxmd
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
 * @brief виртуальная машина
 * @{
*/

                                                        /** @brief слово памяти ВМ */
#define  CELL   int16_t
                                                        /** @brief беззнаковый CELl */
#define UCELL  uint16_t
                                                        /** @rief размер @ref CELL в байтах */
#define CELLsz (sizeof(CELL))

/** 
 * @defgroup bcxconfig конфигурация
 * @{
 * */

                                                        /** @brief размер памяти ВМ в байтах */
#define Msz 0x1000
                                                        /** @brief размер стека возвратов */
#define Rsz 0x100
                                                        /** @brief размер стека данных */
#define Dsz 0x10

/** @} */

                                /** @brief память ВМ (изолированная) */
extern uint8_t M[Msz];
                                /** @brief указатель инструкций */
extern UCELL Ip;
								/** @bried current opcode */
extern uint8_t op;
                                /** @brief указатель компиляции/выделения памяти */
extern UCELL Cp;
                                /** @brief стек возвратов */
extern UCELL R[Rsz];
                                /** @brief вершина стека возвратов */
extern uint8_t Rp;

                                /** @brief стек данных */
extern CELL D[Dsz];
                                /** @brief вершина стека данных */
extern uint8_t Dp;

                                /** @brief снять вершину стека */
extern CELL POP(void);
                                /** @brief получить вершину стека */
extern CELL TOP(void);

							/** @brief интерпретатор байткода */
extern void BCX(void);

/** @} */

							/** @name опкоды */

							/** @brief `NOP ( -- )` пустая команда */
#define op_NOP  0x00
#define op_BYE  0xFF
#define op_JMP  0x01
#define op_qJMP 0x02
#define op_CALL 0x03
#define op_RET  0x04
#define op_LIT  0x05

/**
 * @defgroup debug debug
 * @brief отладка
 * @{
 * */
                            /// `DUMP ( addr size -- )` дамп памяти
extern void DUMP(void);
							/// `NOP ( -- )` do nothing
extern void NOP(void);
                            /// `BYE ( retcode -- )` завершение работы
extern void BYE(void);

// @}

// @}

#endif // _H_BCX
