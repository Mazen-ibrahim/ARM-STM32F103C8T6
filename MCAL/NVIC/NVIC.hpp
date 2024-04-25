/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date :  22/12/2023    *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: NVIC        *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef NVIC_HPP_
#define NVIC_HPP_


typedef enum
{
  NVIC_ERR,
  NVIC_SUCCESS

}NVIC_STATUS;

typedef enum
{
  ACTIVE,
  NOT_ACTIVE,
  ERROR

}INTERRUPT_STATUS;


class NVIC
{

  private:
  u8 Interrupt_Number;


  public:
	NVIC(u8 Interrupt_Number);
	NVIC_STATUS Interrupt_Enable();
	NVIC_STATUS Interrupt_Disable();
	NVIC_STATUS Interrupt_EPending();
	NVIC_STATUS Interrupt_DPending();
	NVIC_STATUS Interrupt_Priority(u8 priortity);
	NVIC_STATUS Interrupt_SoftwareTrigger();
	INTERRUPT_STATUS NVIC_Get_STATUS();


};


#endif /* NVIC_HPP_ */
