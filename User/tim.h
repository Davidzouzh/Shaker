#ifndef TIM__
#define TIM__

#include "stm32f10x.h"

#include "key.h"

extern float ActualFreq;


void TIM3_Config(void);//输入捕获用定时器
void TIM4_Config(void);//定时100ms定时器

void Set_Freq(uint8_t freq);

#endif

