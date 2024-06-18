/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 17/6/2024      *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SYSTICK     *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef SYSTICK_REGISTERS_H_
#define SYSTICK_REGISTERS_H_

#define SYSTICK_BASE_ADDRESS    0xE000E010

typedef struct
{
  volatile u32 CTRL;
  volatile u32 LOAD;
  volatile u32 VAL;


}SYSTICK_REGISTERS;


#define _SYSTICK     ((SYSTICK_REGISTERS*     )(SYSTICK_BASE_ADDRESS))



#endif
