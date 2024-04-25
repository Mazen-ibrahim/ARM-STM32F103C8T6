/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 26/12/2023     *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: CLCD        *************
 **********
 ********** Version: 1.0          *************
 **********************************************/

#include "STD_TYPES.h"
#include "GPIO.hpp"
#include "CLCD.hpp"

CLCD::CLCD(CLCD_TYPE type, GPIO_NAME port , u8 RS_PIN , u8 RW_PIN , u8 EN_PIN)
{
	this->type   = type;
	this->port   = port;
	this->RS_PIN = RS_PIN;
	this->RW_PIN = RW_PIN;
	this->EN_PIN = EN_PIN;

	GPIO::GPIO_Config(port, OUTPUT_10MHz,OUT_PUSHPULL,11);

	Init();

}


void CLCD::Send_Command(u8 Command)
{
	//Set RS_Pin to Low for Command
	GPIO::GPIO_SET_PIN(port, RS_PIN, LOW);

	//Set RW_Pin to Low for Write
	GPIO::GPIO_SET_PIN(port, RW_PIN, LOW);

	//Send Command Data
	GPIO::GPIO_SET_PORT(port,Command);

	//Set Enable Pulse
	GPIO::GPIO_SET_PIN(port, EN_PIN, HIGH);

	for(int i = 0 ; i < 20000 ; i++);

	GPIO::GPIO_SET_PIN(port, EN_PIN, LOW);

}


void CLCD::Send_Data(u8 Data)
{
	//Set RS_Pin to HIGH for Data
	GPIO::GPIO_SET_PIN(port, RS_PIN, HIGH);

	//Set RW_Pin to Low for Write
	GPIO::GPIO_SET_PIN(port, RW_PIN, LOW);

	//Send Data
	GPIO::GPIO_SET_PORT(port,Data);

	//Set Enable Pulse
	GPIO::GPIO_SET_PIN(port, EN_PIN, HIGH);

	for(int i = 0 ; i < 20000 ; i++);

	GPIO::GPIO_SET_PIN(port, EN_PIN, LOW);
}


void CLCD::Clear()
{
	// function clear Display
	Send_Command(0b00000001);
}


void CLCD::Init()
{

	for(int i = 0 ; i < 40000 ; i++);

	if(type == _16X1)
	{
		// function set command : 1 Lines ,5*8 FontSize
		Send_Command(0b00110000);
	}

	else if(type == _16X2)
	{
		// function set command : 2 Lines ,5*8 FontSize
		Send_Command(0b00111000);
	}

	else if(type == _20X4)
	{
		// function set command : 2 Lines ,5*8 FontSize
		Send_Command(0b00111000);
	}


	// function Display on / off : enable display , disable cursor, disable blink
	Send_Command(0b00001100);

	// function clear Display
	Send_Command(0b00000001);
}


void CLCD::GoToXY(u8 X_Pos, u8 Y_Pos)
{

	u8 Local_u8Adress;
	if(X_Pos == 0)
	{
		Local_u8Adress = Y_Pos;
	}

	else if (X_Pos == 1)
	{
		Local_u8Adress = Y_Pos + 0x40;
	}

	else if (X_Pos == 2)
	{
		Local_u8Adress = Y_Pos + 0x14;
	}

	else if (X_Pos == 3)
	{
		Local_u8Adress = Y_Pos + 0x54;
	}

	Send_Command(Local_u8Adress+128);
}


void CLCD::Send_String(const char *String)
{

	u8 index = 0;
	while(String[index] != '\0')
	{
		Send_Data(String[index]);
		index++;
	}

}


void CLCD::Send_Special_Character(u8 *Pattern, u8 Pattern_Number, u8 X_Pos, u8 Y_Pos)
{
    u8 CGRAM_Address = 0;
    u8 Iterator = 0;

    /* Calculate CGRAM Address */
    CGRAM_Address = Pattern_Number*8;

    /* Send  CGRAM Address command to  LCD  */
    Send_Command(CGRAM_Address + 64);

    for(Iterator = 0 ; Iterator < 8 ; Iterator++)
    {
    	Send_Data(Pattern[Iterator]);
    }

    /* Go Back to Position X & Y */
    GoToXY(X_Pos, Y_Pos);


    /* Display Pattern */
    Send_Data(Pattern_Number);



}


void CLCD::Send_Number(u32 Number)
{
	u8 index = 14;
	u8 arr[15] = {0};
    u8 number;

    while(Number > 0)
    {
    	number = Number % 10 ;
    	arr[index--] = number + 48;
    	Number /= 10;
    }

    for( index = 0 ; index < 15 ; index++)
    {
    	if(arr[index] == 0)
    		continue;
    	else
    	  Send_Data(arr[index]);
    }


}


void CLCD::Send_2Lines(const char*Line_1 , const char*Line_2)
{

	Send_Command(0b00000001);

	GoToXY(0,0);
	Send_String(Line_1);

	GoToXY(1,0);
	Send_String(Line_2);
}


void CLCD::Send_3Lines(const char *Line_1 , const char *Line_2 , const char *Line_3)
{
	Send_Command(0b00000001);

	GoToXY(0,0);
	Send_String(Line_1);

	GoToXY(1,0);
	Send_String(Line_2);

	GoToXY(2,0);
	Send_String(Line_3);

}


void CLCD ::Send_4Lines(const char *Line_1 , const char *Line_2 , const char *Line_3, const char *Line_4)
{
	Send_Command(0b00000001);

	GoToXY(0,0);
	Send_String(Line_1);

	GoToXY(1,0);
	Send_String(Line_2);

	GoToXY(2,0);
	Send_String(Line_3);

	GoToXY(3,0);
	Send_String(Line_4);


}
