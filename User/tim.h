#ifndef TIM__
#define TIM__

#include "stm32f10x.h"

extern uint16_t freq;
extern uint16_t BasePWM[6];


void TIM3_Config(void);//输入捕获用定时器
void TIM4_Config(void);//定时100ms定时器
void TIM5_Config(void);//用于ADC3的触发用定时器

#endif

