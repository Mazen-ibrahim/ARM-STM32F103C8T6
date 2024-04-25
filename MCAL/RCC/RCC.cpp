/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date :  14/12/2023    *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: RCC         *************
 ********** Version: 1.0          *************
 **********************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_Registers.h"
#include "RCC.hpp"

RCC::RCC()
{

}

void RCC::APB1_Enable_Peripheral(APB1_Peripheral peripheral_Name)
{
    SET_BIT(Rcc->APB1ENR,peripheral_Name);
}


void RCC::APB2_Enable_Peripheral(APB2_Peripheral peripheral_Name)
{
	SET_BIT(Rcc->APB2ENR,peripheral_Name);
}


void RCC::AHB_Enbale_Peripheral(AHB_Peripheral peripheral_Name)
{
	SET_BIT(Rcc->AHBENR,peripheral_Name);
}


void RCC::APB1_Reset_Peripheral(APB1_Peripheral peripheral_Name)
{
    SET_BIT(Rcc->APB1RSTR,peripheral_Name);
}


void RCC::APB2_Reset_Peripheral(APB2_Peripheral peripheral_Name)
{
	SET_BIT(Rcc->APB2RSTR,peripheral_Name);
}


void RCC::AHB_Reset_Peripheral(AHB_Peripheral peripheral_Name)
{
	CLR_BIT(Rcc->AHBENR,peripheral_Name);
}
