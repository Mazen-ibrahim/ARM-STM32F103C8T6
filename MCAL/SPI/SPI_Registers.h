/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 5/5/2024       *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SPI         *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_
#include "STD_TYPES.h"


#define SPI_BASE_ADDRESS     0x40013000


typedef struct
{
 volatile u32 CR1;
 volatile u32 CR2;
 volatile u32 SR;
 volatile u32 DR;
 volatile u32 CRCR;
 volatile u32 RXCRCR;
 volatile u32 TXCRCR;
 volatile u32 I2SCFGR;
 volatile u32 I2SPR;

}SPI_REGISTERS;



#define _SPI     ((SPI_REGISTERS*     )(SPI_BASE_ADDRESS))





#endif
