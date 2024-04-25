/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date :  14/12/2023    *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: RCC         *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef RCC_REGISTERS_H_
#define RCC_REGISTERS_H_
#include "STD_TYPES.h"

/*********************  RCC BASE ADDRESS    ********************/
#define RCC_BASE_ADDRESS      0x40021000
/***************************************************************/

typedef struct
{
  volatile u32	CR;
  volatile u32  CFGR;
  volatile u32  CIR;
  volatile u32  APB2RSTR;
  volatile u32  APB1RSTR;
  volatile u32  AHBENR;
  volatile u32  APB2ENR;
  volatile u32  APB1ENR;
  volatile u32  BDCR;
  volatile u32  CSR;
  volatile u32  AHBRSTR;
  volatile u32  CFGR2;

}RCC_REGISTERS;


#define  Rcc   ((RCC_REGISTERS*)(RCC_BASE_ADDRESS))



#endif /* RCC_REGISTERS_H_ */
