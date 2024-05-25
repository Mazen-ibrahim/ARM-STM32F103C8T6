/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 5/5/2024       *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SPI         *************
 ********** Version: 1.0          *************
 **********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Registers.h"
#include "SPI.hpp"
#include "SPI_Config.h"

SPI::SPI(SPI_CONFIG *SPI_Configuration)
{
	if(SPI_Configuration != 0 )
	{
		if(SPI_Configuration->CLK_Phase == SECOND_CAP)
		{
			SET_BIT(_SPI->CR1 , 0);
		}

		if(SPI_Configuration->CLK_Polarity == HIGH_IDLE)
		{
			SET_BIT(_SPI->CR1, 1);
		}

		if(SPI_Configuration->SPI_DATA_Frame == _16DATA_BIT)
		{
			SET_BIT(_SPI->CR1, 11);
		}

		if(SPI_Configuration->SPI_ERRIE == enable)
		{
			SET_BIT(_SPI->CR2, 5);
		}

		if(SPI_Configuration->SPI_Frame == LSB)
		{
			SET_BIT(_SPI->CR1, 7);
		}

		if(SPI_Configuration->SPI_RXNEIE == enable)
		{

			SET_BIT(_SPI->CR2, 6);
		}

		if(SPI_Configuration->SPI_Selection == MASTER)
		{
			SET_BIT(_SPI->CR1, 2);
		}


		if(SPI_Configuration->SPI_Slave_Mange == SSME)
		{
			SET_BIT(_SPI->CR1, 9);
		}

		if(SPI_Configuration->SPI_TXEIE == enable)
		{
			SET_BIT(_SPI->CR2, 7);

		}


		if(SPI_Configuration->SPI_Type == OUT_DISABLE)
		{
			SET_BIT(_SPI->CR1, 10);
		}


		//Enable SPI
		SET_BIT(_SPI->CR1, 6);

	}


	else
	{

		DefaultInit();

	}


}

void SPI::DefaultInit()
{

#if CLK_PHASE == SECOND_CAP
	SET_BIT(_SPI->CR1 , 0);
#endif

#if CLK_POLARITY == HIGH_IDLE
	SET_BIT(_SPI->CR1, 1);
#endif

#if SPI_SELCECTION == MASTER
	SET_BIT(_SPI->CR1, 2);
#endif

#if  SPI_FRAME == LSB
	SET_BIT(_SPI->CR1, 7);
#endif

#if SPI_SLAVE_MANGE == SSME
	SET_BIT(_SPI->CR1, 9);
#endif

#if SPI_TYPE == OUT_DISABLE
	SET_BIT(_SPI->CR1, 10);
#endif

#if SPI_DFF ==_16DATA_BIT
	SET_BIT(_SPI->CR1, 11);
#endif

	//Enable SPI
	SET_BIT(_SPI->CR1, 6);

}


void SPI::Disable()
{
	CLR_BIT(_SPI->CR1, 6);
}


void SPI::Enable()
{
	SET_BIT(_SPI->CR1, 6);
}


void SPI::RXNEI_Disable()
{
	CLR_BIT(_SPI->CR2, 6);
}


void SPI::RXNEI_Enable()
{
	SET_BIT(_SPI->CR2, 6);
}

void SPI::TXEI_Enable()
{
	SET_BIT(_SPI->CR2, 7);
}


void SPI::TXEI_Disable()
{
	CLR_BIT(_SPI->CR2, 7);
}


void SPI::ERRI_Enable()
{
	SET_BIT(_SPI->CR2, 5);
}


void SPI::ERRD_Disable()
{
	CLR_BIT(_SPI->CR2, 5);
}

void SPI::SendByte(u8 Msg)
{
	while( GET_BIT(_SPI->SR,1) == 0 );
	_SPI->DR = Msg;
}

u8 SPI::RecieveByte()
{
	while( GET_BIT(_SPI->SR,0) == 0 );
	return _SPI->DR;
}

SPI_STATUS SPI::Transive(u8 *Send_Msg ,u8 *Recieve_Msg , u8 Data_Size)
{
	SPI_STATUS Status = OK;

	for( int i = 0 ; i < Data_Size ; i++ )
	{
		while( GET_BIT(_SPI->SR,1) == 0 );
		_SPI->DR = Send_Msg[i];

		while( GET_BIT(_SPI->SR,0) == 0 );
		Recieve_Msg[i] = _SPI->DR;

		if( GET_BIT(_SPI->SR, 3) == 1 || GET_BIT(_SPI->SR, 6) == 1)
			return Status = NOK;
	}

	return Status;
}


