/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 26/12/2023     *************
 ********** Target: Stm32f103c8t6 *************
 ********** SoftWare: CLCD        *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef CLCD_HPP_
#define CLCD_HPP_

typedef enum
{
  _16X1,
  _16X2,
  _16X4,
  _20X4

}CLCD_TYPE;



class CLCD
{
  private:
    CLCD_TYPE  type;
    GPIO_NAME  port;
    u8 RS_PIN;
    u8 RW_PIN;
    u8 EN_PIN;

  public:

	CLCD(CLCD_TYPE type, GPIO_NAME port , u8 RS_PIN , u8 RW_PIN , u8 EN_PIN);
	void Init();
	void Clear();
	void GoToXY(u8 X_Pos , u8 Y_Pos);
	void Send_Command(u8 Command);
	void Send_Data(u8 Data);
	void Send_String(const char*String);
	void Send_Special_Character(u8 *Pattern, u8 Pattern_Number , u8 X_Pos , u8 Y_Pos);
	void Send_Number(u32 Number);
	void Send_2Lines(const char *Line_1 , const char *Line_2);
	void Send_3Lines(const char *Line_1 , const char *Line_2 , const char *Line_3);
	void Send_4Lines(const char *Line_1 , const char *Line_2 , const char *Line_3, const char *Line_4);
};



#endif /* CLCD_HPP_ */
