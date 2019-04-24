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

						/** @name опкоды */

						/** @brief `NOP ( -- )` пустая команда */
#define op_NOP  0x00
#define op_BYE  0xFF
#define op_JMP  0x01
#define op_qJMP 0x02
#define op_CALL 0x03
#define op_RET  0x04
#define op_LIT  0x05

// @}

#endif // _H_BCX
