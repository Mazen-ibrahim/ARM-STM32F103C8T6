/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date :  22/12/2023    *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: NVIC        *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef NVIC_REGISTER_H_
#define NVIC_REGISTER_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define NVIC_BASE_ADDRESS   0xE000E100
#define NVIC_ISER_OFFSET    0x000
#define NVIC_ICER_OFFSET    0x080
#define NVIC_ISPR_OFFSET    0x100
#define NVIC_ICPR_OFFSET    0x180
#define NVIC_IABR_OFFSET    0x200
#define NVIC_IPR_OFFSET     0x300
#define NVIC_STIR_OFFSET    0xE00


typedef struct
{
	volatile u32 ISER0;
	volatile u32 ISER1;
	volatile u32 ISER2;

}NVIC_REG_ISER;


typedef struct
{
	volatile u32 ICER0;
	volatile u32 ICER1;
	volatile u32 ICER2;

}NVIC_REG_ICER;


typedef struct
{
	volatile u32 ISPR0;
	volatile u32 ISPR1;
	volatile u32 ISPR2;

}NVIC_REG_ISPR;


typedef struct
{

	volatile u32 ICPR0;
	volatile u32 ICPR1;
	volatile u32 ICPR2;

}NVIC_REG_ICPR;


typedef struct
{

	volatile u32 IABR0;
	volatile u32 IABR1;
	volatile u32 IABR2;

}NVIC_REG_IABR;


typedef struct
{
	volatile u32 IPR[20];

}NVIC_REG_PRI;




#define _NVIC_STIR  *(((volatile u32*)(NVIC_BASE_ADDRESS + NVIC_STIR_OFFSET)))
#define _NVIC_ISER   ((NVIC_REG_ISER*)(NVIC_BASE_ADDRESS + NVIC_ISER_OFFSET))
#define _NVIC_ICER   ((NVIC_REG_ICER*)(NVIC_BASE_ADDRESS + NVIC_ICER_OFFSET))
#define _NVIC_ISPR   ((NVIC_REG_ISPR*)(NVIC_BASE_ADDRESS + NVIC_ISPR_OFFSET))
#define _NVIC_ICPR   ((NVIC_REG_ICPR*)(NVIC_BASE_ADDRESS + NVIC_ICPR_OFFSET))
#define _NVIC_IABR   ((NVIC_REG_IABR*)(NVIC_BASE_ADDRESS + NVIC_IABR_OFFSET))
#define _NVIC_IPR    ((NVIC_REG_PRI *)(NVIC_BASE_ADDRESS + NVIC_IPR_OFFSET ))





#define MAX_NUM_INTERRUPT     59




#endif /* NVIC_REGISTER_H_ */
