/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date :  14/12/2023    *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: RCC         *************
 ********** Version: 1.0          *************
 **********************************************/


#ifndef RCC_HPP_
#define RCC_HPP_

typedef enum
{
	AFIO    =  0,
	IOPA    =  2,
	IOPB    =  3,
	IOPC    =  4,
	IOPD    =  5,
	IOPE    =  6,
	ADC1    =  9,
	ADC2    =  10,
	TIM1    =  11,
	SPI1    =  12,
	USART1  =  14

}APB2_Peripheral;


typedef enum
{

	TIM2   =   0 ,
	TIM3   =   1 ,
	TIM4   =   2 ,
	TIM5   =   3 ,
	TIM6   =   4 ,
	TIM7   =   5 ,
	WWD    =   11,
	SPI2   =   14,
	SPI3   =   15,
	USART2 =   17,
	USART3 =   18,
	UART4  =   19,
	UART5  =   20,
	I2C1   =   21,
	I2C2   =   22,
	CAN1   =   25,
	CAN2   =   26,
	BKP    =   27,
	PWR    =   28,
	DAC    =   29

}APB1_Peripheral;



typedef enum
{
   DMA1 = 0,
   DMA2 = 1

}AHB_Peripheral;


typedef enum
{
	RCC_AHB_BUS,
	RCC_APB1_BUS,
	RCC_APB2_BUS

}BUS_NAME;


typedef enum
{
  RCC_ERR,
  RCC_SUCCESS

}RCC_STATUS;




class RCC
{
private:


public:
	RCC();
	void APB1_Enable_Peripheral(APB1_Peripheral peripheral_Name);
	void APB2_Enable_Peripheral(APB2_Peripheral peripheral_Name);
	void AHB_Enbale_Peripheral(AHB_Peripheral peripheral_Name);
	void APB1_Reset_Peripheral(APB1_Peripheral peripheral_Name);
	void APB2_Reset_Peripheral(APB2_Peripheral peripheral_Name);
	void AHB_Reset_Peripheral(AHB_Peripheral peripheral_Name);


};




#endif /* RCC_HPP_ */
