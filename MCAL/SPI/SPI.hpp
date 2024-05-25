/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 5/5/2024       *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SPI         *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef SPI_HPP_
#define SPI_HPP_


typedef enum
{
  FIRST_CAP ,
  SECOND_CAP

}CLK_PHASE;

typedef enum
{
  LOW_IDLE,
  HIGH_IDLE

}CLK_POLARTIY;


typedef enum
{
  SLAVE,
  MASTER

}SPI_SELECTION;


typedef enum
{
  MSB,
  LSB

}SPI_FRAME;


typedef enum
{
  SSMD,
  SSME

}SPI_SLAVE_MANGE;


typedef enum
{
  FULL_DUPLEX,
  OUT_DISABLE

}SPI_TYPE;


typedef enum
{
  _8DATA_BIT,
  _16DATA_BIT

}SPI_DFF;



typedef enum
{
  NULL,
  disable,
  enable,
  OK,
  NOK,

}SPI_STATUS;


typedef struct
{
  CLK_PHASE         CLK_Phase;
  CLK_POLARTIY      CLK_Polarity;
  SPI_SELECTION     SPI_Selection;
  SPI_FRAME         SPI_Frame;
  SPI_SLAVE_MANGE   SPI_Slave_Mange;
  SPI_TYPE          SPI_Type;
  SPI_DFF           SPI_DATA_Frame;
  SPI_STATUS        SPI_ERRIE;
  SPI_STATUS        SPI_RXNEIE;
  SPI_STATUS        SPI_TXEIE;

}SPI_CONFIG;



class SPI
{

  private:


  public:
	SPI(SPI_CONFIG *SPI_Configuration);
	void DefaultInit();
	void Enable();
	void Disable();
	void ERRI_Enable();
	void ERRD_Disable();
	void RXNEI_Enable();
	void RXNEI_Disable();
	void TXEI_Enable();
	void TXEI_Disable();
	void SendByte(u8 Msg);
	u8   RecieveByte();
    SPI_STATUS Transive(u8 *Send_Msg ,u8 *Recieve_Msg , u8 Data_Size);

};








#endif
