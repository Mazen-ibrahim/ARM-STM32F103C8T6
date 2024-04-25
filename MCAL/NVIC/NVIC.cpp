/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date :  22/12/2023    *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: NVIC        *************
 ********** Version: 1.0          *************
 **********************************************/

#include "NVIC_Register.h"
#include "NVIC.hpp"

NVIC::NVIC(u8 Interrupt_Number)
{
	this->Interrupt_Number = Interrupt_Number;
}

NVIC_STATUS NVIC::Interrupt_Enable()
{
	NVIC_STATUS Status = NVIC_SUCCESS;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = NVIC_ERR;
	}

	else
	{
		if(Interrupt_Number < 32 )
		{
			SET_BIT(_NVIC_ISER->ISER0 ,Interrupt_Number);
		}

		else if (Interrupt_Number <= MAX_NUM_INTERRUPT )
		{
			SET_BIT(_NVIC_ISER->ISER1 ,Interrupt_Number);
		}
	}


	return Status;

}

NVIC_STATUS NVIC::Interrupt_Disable()
{
	NVIC_STATUS Status = NVIC_SUCCESS;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = NVIC_ERR;
	}

	else
	{
		if(Interrupt_Number < 32 )
		{
			SET_BIT(_NVIC_ICER->ICER0 ,Interrupt_Number);
		}

		else if (Interrupt_Number <= MAX_NUM_INTERRUPT )
		{
			SET_BIT(_NVIC_ICER->ICER1 ,Interrupt_Number);
		}
	}


	return Status;
}

NVIC_STATUS NVIC::Interrupt_EPending()
{
	NVIC_STATUS Status = NVIC_SUCCESS;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = NVIC_ERR;
	}

	else
	{
		if(Interrupt_Number < 32 )
		{
			SET_BIT(_NVIC_ISPR->ISPR0 ,Interrupt_Number);
		}

		else if (Interrupt_Number <= MAX_NUM_INTERRUPT )
		{
			SET_BIT(_NVIC_ISPR->ISPR1 ,Interrupt_Number);
		}
	}


	return Status;
}


NVIC_STATUS NVIC::Interrupt_DPending()
{
	NVIC_STATUS Status = NVIC_SUCCESS;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = NVIC_ERR;
	}

	else
	{
		if(Interrupt_Number < 32 )
		{
			SET_BIT(_NVIC_ICPR->ICPR0 ,Interrupt_Number);
		}

		else if (Interrupt_Number <= MAX_NUM_INTERRUPT )
		{
			SET_BIT(_NVIC_ICPR->ICPR1 ,Interrupt_Number);
		}
	}


	return Status;
}


NVIC_STATUS NVIC::Interrupt_Priority(u8 priortity)
{
	u8 Register_Num  = Interrupt_Number / 4;
	u8 Interrupt_offset = (Interrupt_Number % 4) * 8;
	priortity = priortity<<4;

	NVIC_STATUS Status = NVIC_SUCCESS;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = NVIC_ERR;
	}

	else
	{
          _NVIC_IPR->IPR[Register_Num] |= priortity<<Interrupt_offset;
	}


	return Status;


}

NVIC_STATUS NVIC::Interrupt_SoftwareTrigger()
{
	NVIC_STATUS Status = NVIC_SUCCESS;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = NVIC_ERR;
	}

	else
	{
		_NVIC_STIR = Interrupt_Number;
	}


	return Status;
}


INTERRUPT_STATUS NVIC::NVIC_Get_STATUS()
{
	INTERRUPT_STATUS Status ;
	if(Interrupt_Number > MAX_NUM_INTERRUPT )
	{
		Status = ERROR;
	}

	else
	{
		if(Interrupt_Number < 32 )
		{
			Status = (INTERRUPT_STATUS) GET_BIT(_NVIC_IABR->IABR0 ,Interrupt_Number);
		}

		else if (Interrupt_Number <= MAX_NUM_INTERRUPT )
		{
			Status = (INTERRUPT_STATUS) GET_BIT(_NVIC_IABR->IABR1 ,Interrupt_Number);
		}

	}


	return Status;
}


