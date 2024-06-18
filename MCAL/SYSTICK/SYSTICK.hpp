/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 17/6/2024      *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SYSTICK     *************
 ********** Version: 1.0          *************
 **********************************************/



#ifndef SYSTICK_HPP_
#define SYSTICK_HPP_


using Function_Pointer = void(*)(void);


typedef enum
{
  AHB_8 ,
  AHB

}CLK_SRC;


typedef enum
{
 DISABLE,
 ENABLE,
 NOK,
 OK
}STATUS;


class SYSTICK
{

   private:


   public:
   SYSTICK( CLK_SRC Src , u32 load_val );
   void Enable();
   void Disable();
   void Enable_Interrupt();
   void Disable_Interrupt();
   void Busy_Wait();
   void Set_Reload_Val(u32 value);
   u32  Get_Current_Val();
   void Set_Callback(Function_Pointer func);

};




#endif /* SYSTICK_HPP_ */
