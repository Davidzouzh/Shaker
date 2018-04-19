

#include "Encoder.h"



//码盘的引脚初始化 
void Encoder_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
	TIM_ICInitTypeDef TIM_ICInitStructure;      
	NVIC_InitTypeDef NVIC_InitStructure;

	//使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_TIM1, ENABLE);//使能TIM1时钟  
 
	//引脚初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//PA8 PA9浮空输入  
	GPIO_Init(GPIOA, &GPIO_InitStructure); 

	//时钟初始化
	TIM_DeInit(TIM1);  
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);  
	TIM_TimeBaseStructure.TIM_Prescaler = 0;  // No prescaling //设定计数器分频系数为0，不分频  
	TIM_TimeBaseStructure.TIM_Period = 65535;  //设定计数器重装值   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//设置时钟分割 T_dts = T_ck_int   
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   //TIM向上计数  
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);  

	//
	TIM_EncoderInterfaceConfig(TIM1, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
	
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 6;//选择输入比较滤波器  
	TIM_ICInit(TIM1, &TIM_ICInitStructure);
	
	//中断
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure); 

	//清空所有的标志位
	TIM_ClearFlag(TIM1, TIM_FLAG_Update); 
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);  

	//重置
	TIM_SetCounter(TIM1, 0);
	
	//使能
	TIM_Cmd(TIM1, ENABLE);  
}



//获取码盘的读值 
uint16_t Get_EncoderValue(void)
{
	uint16_t Encoder;
	
	Encoder = TIM_GetCounter(TIM1);
	
	TIM_SetCounter(TIM1, 0);
	
	return Encoder;
}



