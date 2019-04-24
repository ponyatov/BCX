/** @file 
 * @brief `bcx:FORTH` переносимая виртуальная машина (для микроконтроллеров)
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
 * @defgroup bcxvm vm
 * @brief виртуальная машина
 * @{
*/
                                /** @brief байт */
#define  BYTE   uint8_t
                                /** @brief слово памяти ВМ */
#define  CELL   int16_t
                                /** @brief беззнаковый @ref CELL */
#define UCELL  uint16_t
                                /** @brief размер @ref CELL в байтах */
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
extern BYTE M[Msz];
                                /** @brief указатель инструкций */
extern UCELL Ip;
			        /** @brief опкод текущей команды */
extern BYTE op;
                                /** @brief указатель компиляции/выделения памяти */
extern UCELL Cp;
                                /** @brief стек возвратов */
extern UCELL R[Rsz];
                                /** @brief вершина стека возвратов */
extern BYTE Rp;

                                /** @brief стек данных */
extern CELL D[Dsz];
                                /** @brief вершина стека данных */
extern BYTE Dp;

                                /** @brief снять вершину стека */
extern CELL POP(void);
                                /** @brief получить вершину стека */
extern CELL TOP(void);

							/** @brief интерпретатор байткода */
extern void BCX(void);

/** 
 * @defgroup bcxcmd команды
 * @{ */

/**
 * @defgroup bcxcflow управление потоком выполнения
 * @{ */

			    /** @brief `NOP ( -- )` пустая команда */
#define op_NOP  0x00
extern void NOP(void);

                            /** @brief `BYE ( retcode -- )` завершение работы */
#define op_BYE  0xFF
extern void BYE(void);

                            /** @brief `JMP ( -- )` безусловный переход */
#define op_JMP  0x01
extern void JMP(void);

                            /** @brief `?JMP ( false -- )` условный переход по false */
#define op_qJMP 0x02
extern void qJMP(void);
                            /** @brief `CALL (R: -- addr )` вложенный вызов */
#define op_CALL 0x03
extern void CALL(void);
                            /** @brief `RET (R: addr -- )` возврат */
#define op_RET  0x04
extern void RET(void);
                            /** @brief `LIT ( -- int )` числовой литерал (поместить константу в стек) */
#define op_LIT  0x05
extern void LIT(void);

/** @} bcxcflow */

/**
 * @defgroup debug отладка
 * @{
 * */
                            /// @brief `DUMP ( addr size -- )` дамп памяти
extern void DUMP(void);

/** @} debug */

/// @} bcxcmd

extern void store(UCELL addr, CELL cell);
extern void Bcompile(uint8_t);
extern void compile(CELL cell);

// @}

#endif // _H_BCX
