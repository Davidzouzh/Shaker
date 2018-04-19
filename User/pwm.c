

#include "PWM.h"


void PWM_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
	TIM_OCInitTypeDef TIM_OCInitStructure; 
	
	//时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	//对时钟进行设置  PCLK1经过2倍频后作为TIM3的时钟源等于72MHz
	
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		// 复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//时间基准设置
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_Period = 999;  
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//PWM波频率：72Mhz/1000/1=72Khz	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		//设置时钟分频系数：不分频  
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//向上计数溢出模式  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	//通道设置
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//配置为PWM模式1  
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;                
	TIM_OCInitStructure.TIM_Pulse = 0;		//设置跳变值，当计数器计数到这个值时，电平发生跳变  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//当定时器计数值小于CCR1时为高电平  
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);

	//预装载使能	
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	//使能重载寄存器ARR
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	TIM_Cmd(TIM2, ENABLE);
}


void MotorPwmFlash(int16_t MOTO_PWM)
{		
	if(MOTO_PWM>=Moto_PwmMax)	MOTO_PWM = Moto_PwmMax;
	if(MOTO_PWM<=0)	MOTO_PWM = 0;		//限定输入不能小于0，大于999
    
    TIM2->CCR1 = MOTO_PWM;        //对定时器寄存器赋值
}

