/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 17/6/2024      *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SYSTICK     *************
 ********** Version: 1.0          *************
 **********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_Registers.h"
#include "SYSTICK.hpp"


static Function_Pointer CallBack;

SYSTICK::SYSTICK( CLK_SRC Src , u32 load_val )
{

	if(Src == AHB || Src == AHB_8)
		_SYSTICK->CTRL |= Src;

	if(load_val >= 0x00000001 && load_val <= 0x00FFFFFF)
		_SYSTICK->LOAD = load_val;

	else
		load_val = 0x00FFFFFF;

    SET_BIT(_SYSTICK->CTRL , 1);

    SET_BIT(_SYSTICK->CTRL , 0);


}


void SYSTICK::Enable()
{
    SET_BIT(_SYSTICK->CTRL , 0);
}


void SYSTICK::Disable()
{
	CLR_BIT(_SYSTICK->CTRL , 0);
}


void SYSTICK::Enable_Interrupt()
{
    SET_BIT(_SYSTICK->CTRL , 1);
}


void SYSTICK::Disable_Interrupt()
{
	 CLR_BIT(_SYSTICK->CTRL , 1);
}


void SYSTICK::Set_Reload_Val(u32 value)
{
	if(value >= 0x00000001 && value <= 0x00FFFFFF)
		_SYSTICK->LOAD = value;
	else
		value = 0x00FFFFFF;
}

u32 SYSTICK::Get_Current_Val()
{
	return _SYSTICK->VAL;
}


void SYSTICK::Busy_Wait()
{
    while(GET_BIT(_SYSTICK->CTRL,16) == 0);
    CLR_BIT(_SYSTICK->CTRL,16);
}

void SYSTICK::Set_Callback(Function_Pointer func)
{
	CallBack = func;
}


//ISR of SYSTICK
void SysTick_Handler(void)
{

	CallBack();
}
