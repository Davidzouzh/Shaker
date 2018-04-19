
#include "tim.h"
#include "encoder.h"
#include "pwm.h"

//定时器3初始化
void TIM3_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  //打开时钟
    
    TIM_DeInit(TIM3);
    TIM_TimeBaseStructure.TIM_Period = 10000-1;	//定时100ms
    TIM_TimeBaseStructure.TIM_Prescaler = 720-1;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
    TIM_Cmd(TIM3,ENABLE);
  
}


uint16_t freq = 0;

uint16_t BasePWM[6]={0,100,200,500,800,999};
uint16_t spdTag[6]={0,13,26,66,132,198};
uint16_t spdNow;

int32_t errNow=0;
int32_t errOld=0,errOld2=0,errOld3=0;
int32_t P,I,D;

uint16_t PWM;

const uint16_t kp = 15;
const uint16_t ki = 15;
const uint16_t kd = 15;
const uint16_t errILim = 1000;



void TIM3_IRQHandler(void)
{
	
	if( TIM_GetITStatus(TIM3 , TIM_IT_Update) != RESET ) 
    {
		spdNow = Get_EncoderValue();	//当前速度
		
		errNow = spdNow - spdTag[freq];	//速度差值
		P = errNow;
		I = errNow+errOld+errOld2+errOld3;
		D = errNow-errOld;
		
		if(errILim != 0)	//微分限制
		{
			if(I > errILim)
				I = errILim;
			else if(I < -errILim)
				I = -errILim;
		}

		PWM = (uint16_t)( kp*P+ki*I+kd*D + BasePWM[freq] );	//输出的PWM值，基础PWM值+误差PWM值

		MotorPwmFlash(PWM);
		
		errOld = errNow;	//误差更新
		errOld2 = errOld;
		errOld3 = errOld2;

		TIM_ClearITPendingBit(TIM3, TIM_FLAG_Update);   //清除中断标志
	}
	
}

