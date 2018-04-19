
#ifndef OLED__
#define OLED__

#include "stm32f10x.h"






//OLED¿ØÖÆÓÃº¯Êý
void OLED_Init(void);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);

void OLED_Show1Numwith1Dot(u8 x,u8 y,float num,u8 size);

void OLED_ShowString(u8 x,u8 y, u8 *p,u8 size);	 
void OLED_ShowCHinese(u8 x,u8 y,u8 num,u8 size);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);

#endif  

