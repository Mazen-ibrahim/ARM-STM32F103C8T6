/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 14/12/2023     *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: GPIO        *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef GPIO_REGISTERS_H_
#define GPIO_REGISTERS_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/***************** GPIO ADRESSES ********************/
#define GPIOA_BASE_ADDRESS    0x40010800
#define GPIOB_BASE_ADDRESS    0x40010C00
#define GPIOC_BASE_ADDRESS    0x40011000
#define GPIOD_BASE_ADDRESS    0x40011400
#define GPIOE_BASE_ADDRESS    0x40011800
#define GPIOF_BASE_ADDRESS    0x40011C00
#define GPIOG_BASE_ADDRESS    0x40012000
/****************************************************/

typedef struct
{
  volatile u32 CRL;
  volatile u32 CRH;
  volatile u32 IDR;
  volatile u32 ODR;
  volatile u32 BSRR;
  volatile u32 BRR;
  volatile u32 LCKR;



}GPIO_REGISTERS;


#define GPIOA    ((GPIO_REGISTERS*)(GPIOA_BASE_ADDRESS))
#define GPIOB    ((GPIO_REGISTERS*)(GPIOB_BASE_ADDRESS))
#define GPIOC    ((GPIO_REGISTERS*)(GPIOC_BASE_ADDRESS))
#define GPIOD    ((GPIO_REGISTERS*)(GPIOD_BASE_ADDRESS))
#define GPIOE    ((GPIO_REGISTERS*)(GPIOE_BASE_ADDRESS))
#define GPIOF    ((GPIO_REGISTERS*)(GPIOF_BASE_ADDRESS))
#define GPIOG    ((GPIO_REGISTERS*)(GPIOG_BASE_ADDRESS))


#endif /* GPIO_REGISTERS_H_ */
