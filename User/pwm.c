

#include "PWM.h"


void PWM_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
	TIM_OCInitTypeDef TIM_OCInitStructure; 
	
	//ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	//��ʱ�ӽ�������  PCLK1����2��Ƶ����ΪTIM3��ʱ��Դ����72MHz
	
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		// ����������� 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//ʱ���׼����
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_Period = 999;  
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//PWM��Ƶ�ʣ�72Mhz/1000/1=72Khz	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		//����ʱ�ӷ�Ƶϵ��������Ƶ  
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//���ϼ������ģʽ  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	//ͨ������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//����ΪPWMģʽ1  
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;                
	TIM_OCInitStructure.TIM_Pulse = 0;		//��������ֵ�������������������ֵʱ����ƽ��������  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//����ʱ������ֵС��CCR1ʱΪ�ߵ�ƽ  
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);

	//Ԥװ��ʹ��	
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	//ʹ�����ؼĴ���ARR
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	TIM_Cmd(TIM2, ENABLE);
}


void MotorPwmFlash(int16_t MOTO_PWM)
{		
	if(MOTO_PWM>=Moto_PwmMax)	MOTO_PWM = Moto_PwmMax;
	if(MOTO_PWM<=0)	MOTO_PWM = 0;		//�޶����벻��С��0������999
    
    TIM2->CCR1 = MOTO_PWM;        //�Զ�ʱ���Ĵ�����ֵ
}

