/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 14/12/2023     *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: GPIO        *************
 ********** Version: 1.0          *************
 **********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO.hpp"
#include "GPIO_Registers.h"


GPIO::GPIO(GPIO_NAME GPIO_Name, GPIO_PIN_TYPE GPIO_type, u8 GPIO_CONFIG ,u8 GPIO_PIN)
{
	this->GPIO_Name = GPIO_Name;
	this->GPIO_type = GPIO_type;
	this->GPIO_CONFIG = GPIO_CONFIG;
	this->GPIO_PIN  = GPIO_PIN;

	INIT();
}


GPIO_STATUS GPIO::INIT()
{
	if( GPIO_Name > _GPIOG || GPIO_Name < _GPIOA )
		return GPIO_ERR_NAME;

	else if(GPIO_type <INPUT || GPIO_type > OUTPUT_50MHz)
		return GPIO_ERR_TYPE;

	else if (GPIO_CONFIG < ANALOG || GPIO_CONFIG > ALT_OPENDRAIN )
		return GPIO_ERR_CNF;

	else if ( GPIO_PIN > 15 )
		return GPIO_ERR_PIN;





	switch(GPIO_Name)
	{
	case _GPIOA:
		if(GPIO_PIN >=8)
		{
			GPIOA->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOA->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOA->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOA->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;


	case _GPIOB:

		if(GPIO_PIN >=8)
		{
			GPIOB->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOB->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOB->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOB->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;


	case _GPIOC:

		if(GPIO_PIN >=8)
		{
			GPIOC->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOC->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOC->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOC->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;

	case _GPIOD:

		if(GPIO_PIN >=8)
		{
			GPIOD->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOD->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOD->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOD->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;



	case _GPIOE:

		if(GPIO_PIN >=8)
		{
			GPIOE->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOE->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOE->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOE->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;


	case _GPIOF:

		if(GPIO_PIN >=8)
		{
			GPIOF->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOF->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOF->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOF->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;

	case _GPIOG:

		if(GPIO_PIN >=8)
		{
			GPIOG->CRH |= GPIO_type<<(GPIO_PIN-8)*4;
			GPIOG->CRH |= GPIO_CONFIG<<(GPIO_PIN-8)*2;
		}
		else
		{
			GPIOG->CRL |= GPIO_type<<(GPIO_PIN*4);
			GPIOG->CRL |= GPIO_CONFIG<<(GPIO_PIN*2);
		}

		break;

	}

	if(GPIO_CONFIG == INPUT_PULLUP)
	{
		switch(GPIO_Name)
		{
		case _GPIOA: SET_BIT(GPIOA->ODR,GPIO_PIN); break;
		case _GPIOB: SET_BIT(GPIOB->ODR,GPIO_PIN); break;
		case _GPIOC: SET_BIT(GPIOC->ODR,GPIO_PIN); break;
		case _GPIOD: SET_BIT(GPIOD->ODR,GPIO_PIN); break;
		case _GPIOE: SET_BIT(GPIOE->ODR,GPIO_PIN); break;
		case _GPIOF: SET_BIT(GPIOF->ODR,GPIO_PIN); break;
		case _GPIOG: SET_BIT(GPIOG->ODR,GPIO_PIN); break;
		}
	}


	return GPIO_SUCCESS;

}


PIN_STATUS GPIO::Read_PIN()
{
	PIN_STATUS Status ;
	switch(GPIO_Name)
	{
	case _GPIOA:
		Status = (PIN_STATUS) GET_BIT(GPIOA->IDR,GPIO_PIN);
		break;

	case _GPIOB:
		Status = (PIN_STATUS) GET_BIT(GPIOB->IDR,GPIO_PIN);
		break;

	case _GPIOC:
		Status = (PIN_STATUS) GET_BIT(GPIOC->IDR,GPIO_PIN);
		break;

	case _GPIOD:
		Status = (PIN_STATUS) GET_BIT(GPIOD->IDR,GPIO_PIN);
		break;

	case _GPIOE:
		Status = (PIN_STATUS) GET_BIT(GPIOE->IDR,GPIO_PIN);
		break;

	case _GPIOF:
		Status = (PIN_STATUS) GET_BIT(GPIOF->IDR,GPIO_PIN);
		break;

	case _GPIOG:
		Status = (PIN_STATUS) GET_BIT(GPIOG->IDR,GPIO_PIN);
		break;
	}

	return Status;
}


void GPIO::SET_PIN(PIN_STATUS Status)
{
	switch(GPIO_Name)
	{
	case _GPIOA:
		if(Status == HIGH)
			SET_BIT(GPIOA->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOA->ODR,GPIO_PIN);

		break;

	case _GPIOB:
		if(Status == HIGH)
			SET_BIT(GPIOB->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOB->ODR,GPIO_PIN);

		break;

	case _GPIOC:
		if(Status == HIGH)
			SET_BIT(GPIOC->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOC->ODR,GPIO_PIN);

		break;

	case _GPIOD:
		if(Status == HIGH)
			SET_BIT(GPIOD->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOD->ODR,GPIO_PIN);

		break;

	case _GPIOE:
		if(Status == HIGH)
			SET_BIT(GPIOE->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOE->ODR,GPIO_PIN);

		break;

	case _GPIOF:
		if(Status == HIGH)
			SET_BIT(GPIOF->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOF->ODR,GPIO_PIN);

		break;

	case _GPIOG:
		if(Status == HIGH)
			SET_BIT(GPIOG->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOG->ODR,GPIO_PIN);

		break;
	}

}


void GPIO::RESET_PIN()
{
	switch(GPIO_Name)
	{
	case _GPIOA: SET_BIT(GPIOA->BRR,GPIO_PIN); break;
	case _GPIOB: SET_BIT(GPIOB->BRR,GPIO_PIN); break;
	case _GPIOC: SET_BIT(GPIOC->BRR,GPIO_PIN); break;
	case _GPIOD: SET_BIT(GPIOD->BRR,GPIO_PIN); break;
	case _GPIOE: SET_BIT(GPIOE->BRR,GPIO_PIN); break;
	case _GPIOF: SET_BIT(GPIOF->BRR,GPIO_PIN); break;
	case _GPIOG: SET_BIT(GPIOG->BRR,GPIO_PIN); break;
	}

}


GPIO_STATUS GPIO::GPIO_Config(GPIO_NAME GPIO_Name, GPIO_PIN_TYPE GPIO_type, u8 GPIO_CONFIG, u8 Num_of_Pin)
{
	if( GPIO_Name > _GPIOG || GPIO_Name < _GPIOA )
		return GPIO_ERR_NAME;

	else if(GPIO_type <INPUT || GPIO_type > OUTPUT_50MHz)
		return GPIO_ERR_TYPE;

	else if (GPIO_CONFIG < ANALOG || GPIO_CONFIG > ALT_OPENDRAIN )
		return GPIO_ERR_CNF;

	else if ( Num_of_Pin > 15 )
		return GPIO_ERR_PIN;


	switch(GPIO_Name)
	{
	case _GPIOA:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOA->CRH |= GPIO_type<<(index-8)*4;
				GPIOA->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOA->CRL |= GPIO_type<<(index*4);
				GPIOA->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;


	case _GPIOB:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOB->CRH |= GPIO_type<<(index-8)*4;
				GPIOB->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOB->CRL |= GPIO_type<<(index*4);
				GPIOB->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;


	case _GPIOC:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOC->CRH |= GPIO_type<<(index-8)*4;
				GPIOC->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOC->CRL |= GPIO_type<<(index*4);
				GPIOC->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;

	case _GPIOD:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOD->CRH |= GPIO_type<<(index-8)*4;
				GPIOD->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOD->CRL |= GPIO_type<<(index*4);
				GPIOD->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;



	case _GPIOE:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOE->CRH |= GPIO_type<<(index-8)*4;
				GPIOE->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOE->CRL |= GPIO_type<<(index*4);
				GPIOE->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;


	case _GPIOF:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOF->CRH |= GPIO_type<<(index-8)*4;
				GPIOF->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOF->CRL |= GPIO_type<<(index*4);
				GPIOF->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;

	case _GPIOG:

		for(int index = 0 ; index<Num_of_Pin; index++)
		{
			if( index >=8)
			{
				GPIOG->CRH |= GPIO_type<<(index-8)*4;
				GPIOG->CRH |= GPIO_CONFIG<<(index-8)*2;
			}
			else
			{
				GPIOG->CRL |= GPIO_type<<(index*4);
				GPIOG->CRL |= GPIO_CONFIG<<(index*2);
			}
		}

		break;

	}


	if(GPIO_CONFIG == INPUT_PULLUP)
	{
		switch(GPIO_Name)
		{
		case _GPIOA:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOA->ODR,index);
			}
			break;

		case _GPIOB:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOB->ODR,index);
			}
			break;

		case _GPIOC:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOC->ODR,index);
			}
			break;

		case _GPIOD:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOD->ODR,index);
			}
			break;

		case _GPIOE:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOE->ODR,index);
			}
			break;

		case _GPIOF:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOF->ODR,index);
			}
			break;

		case _GPIOG:
			for(int index = 0 ; index < Num_of_Pin ; index++)
			{
				SET_BIT(GPIOG->ODR,index);
			}
			break;
		}
	}


	return GPIO_SUCCESS;


}


GPIO_STATUS GPIO::GPIO_SET_PORT(GPIO_NAME GPIO_Name , u32 port_Value)
{
	if( GPIO_Name > _GPIOG || GPIO_Name < _GPIOA )
		return GPIO_ERR_NAME;


	switch(GPIO_Name)
	{
	case _GPIOA:
		GPIOA->ODR &= 0xFFFFFF00;
		GPIOA->ODR |= port_Value;
		break;
	case _GPIOB:
		GPIOB->ODR &= 0xFFFFFF00;
		GPIOB->ODR |= port_Value;
		break;
	case _GPIOC:
		GPIOC->ODR &= 0xFFFFFF00;
		GPIOC->ODR |= port_Value;
		break;
	case _GPIOD:
		GPIOD->ODR &= 0xFFFFFF00;
		GPIOD->ODR |= port_Value;
		break;
	case _GPIOE:
		GPIOE->ODR &= 0xFFFFFF00;
		GPIOE->ODR |= port_Value;
		break;
	case _GPIOF:
		GPIOF->ODR &= 0xFFFFFF00;
		GPIOF->ODR |= port_Value;
		break;
	case _GPIOG:
		GPIOG->ODR &= 0xFFFFFF00;
		GPIOG->ODR |= port_Value;
		break;
	}




	return GPIO_SUCCESS;

}


GPIO_STATUS GPIO::GPIO_SET_PIN(GPIO_NAME GPIO_Name , u8 GPIO_PIN , PIN_STATUS Status)
{
	if( GPIO_Name > _GPIOG || GPIO_Name < _GPIOA )
		return GPIO_ERR_NAME;

	else if ( GPIO_PIN > 15 )
		return GPIO_ERR_PIN;


	switch(GPIO_Name)
	{
	case _GPIOA:
		if(Status == HIGH)
			SET_BIT(GPIOA->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOA->ODR,GPIO_PIN);

		break;

	case _GPIOB:
		if(Status == HIGH)
			SET_BIT(GPIOB->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOB->ODR,GPIO_PIN);

		break;

	case _GPIOC:
		if(Status == HIGH)
			SET_BIT(GPIOC->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOC->ODR,GPIO_PIN);

		break;

	case _GPIOD:
		if(Status == HIGH)
			SET_BIT(GPIOD->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOD->ODR,GPIO_PIN);

		break;

	case _GPIOE:
		if(Status == HIGH)
			SET_BIT(GPIOE->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOE->ODR,GPIO_PIN);

		break;

	case _GPIOF:
		if(Status == HIGH)
			SET_BIT(GPIOF->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOF->ODR,GPIO_PIN);

		break;

	case _GPIOG:
		if(Status == HIGH)
			SET_BIT(GPIOG->ODR,GPIO_PIN);
		else
			CLR_BIT(GPIOG->ODR,GPIO_PIN);

		break;
	}





	return GPIO_SUCCESS;

}
