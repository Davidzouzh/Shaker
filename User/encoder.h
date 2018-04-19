#ifndef Encoder__
#define Encoder__

#include "stm32f10x.h"


//码盘
//使用TIM1，编码器模式
//定时器读数值即两次测量的差值，正比于速度


void Encoder_Config(void);

uint16_t Get_EncoderValue(void);

#endif


