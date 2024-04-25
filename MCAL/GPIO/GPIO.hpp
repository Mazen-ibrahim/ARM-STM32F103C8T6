/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 14/12/2023     *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: GPIO        *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef GPIO_HPP_
#define GPIO_HPP_
#include "STD_TYPES.h"

/* Configurations of Pins */
#define  ANALOG          0
#define  FLOAT_INPUT     1
#define  INPUT_PULLUP    2
#define  INPUT_PULLDOWN  2
#define  OUT_PUSHPULL    0
#define  OUT_OPENDRAIN   1
#define  ALT_PUSHPULL    2
#define  ALT_OPENDRAIN   3
/**************************/


typedef enum
{
 _GPIOA,
 _GPIOB,
 _GPIOC,
 _GPIOD,
 _GPIOE,
 _GPIOF,
 _GPIOG,

}GPIO_NAME;


typedef enum
{
  INPUT = 0,
  OUTPUT_10MHz = 1,
  OUTPUT_2MHz  = 2,
  OUTPUT_50MHz = 3

}GPIO_PIN_TYPE;



typedef enum
{
  GPIO_ERR_NAME,
  GPIO_ERR_PIN,
  GPIO_ERR_TYPE,
  GPIO_ERR_CNF,
  GPIO_SUCCESS,

}GPIO_STATUS;



typedef enum
{
  LOW ,
  HIGH
}PIN_STATUS;



class GPIO
{
private:
	 GPIO_NAME GPIO_Name;
	 GPIO_PIN_TYPE GPIO_type;
     u8 GPIO_CONFIG;
	 u8 GPIO_PIN;



public:
	GPIO(GPIO_NAME GPIO_Name, GPIO_PIN_TYPE GPIO_type, u8 GPIO_CONFIG ,u8 GPIO_PIN);
    GPIO_STATUS INIT();
    PIN_STATUS Read_PIN();
    void SET_PIN(PIN_STATUS Status);
    void RESET_PIN();
    static GPIO_STATUS GPIO_Config(GPIO_NAME GPIO_Name, GPIO_PIN_TYPE GPIO_type, u8 GPIO_CONFIG, u8 Num_of_Pin);
    static GPIO_STATUS GPIO_SET_PORT(GPIO_NAME GPIO_Name , u32 port_Value);
    static GPIO_STATUS GPIO_SET_PIN(GPIO_NAME GPIO_Name , u8 GPIO_PIN , PIN_STATUS Status);


};





#endif /* GPIO_HPP_ */
