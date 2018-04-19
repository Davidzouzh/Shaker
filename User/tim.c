
#include "tim.h"

#include "pwm.h"
#include "timer.h"

//定时器3通道3输入捕获配置
void TIM3_Config(void)
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//PB0上拉输入 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_Pin_0);//PB0 上拉
 
	//初始化TIM3	 
	TIM_TimeBaseStructure.TIM_Period = 0XFFFF; //设定计数器自动重装值 
	TIM_TimeBaseStructure.TIM_Prescaler = 71; 	//预分频器   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	//初始化TIM3输入捕获参数
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_3; //CC1S=02 	选择输入端 IC2映射到TI1上
  	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
  	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
  	TIM_ICInitStructure.TIM_ICFilter = 0x06;//IC1F=0000 配置输入滤波器
  	TIM_ICInit(TIM3, &TIM_ICInitStructure);
	
	//中断分组初始化
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器 
	
	TIM_ITConfig(TIM3, TIM_IT_Update|TIM_IT_CC3,ENABLE);//允许更新中断 ,允许CC2IE捕获中断	
	
	TIM_Cmd(TIM3, ENABLE); 	//使能定时器2
 
}


uint16_t TIM3CH3_CAPTURE_VAL;	//输入捕获值
//1us记一次，一次溢出要记65536us，即65ms，电机的最慢转速0.1HZ也是最久41ms一次捕获
//电机最快转速1.5HZ，一次捕获约2.7ms

float ActualFreq;

void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_CC3) != RESET)//捕获3发生捕获事件
	{	
		TIM3CH3_CAPTURE_VAL = TIM3->CCR3;
		//TIM3CH3_CAPTURE_VAL = TIM_GetCapture3(TIM3);
		TIM3->CNT = 0;
		//TIM_SetCounter(TIM3,0);
		
		ActualFreq = 1000000.0/(TIM3CH3_CAPTURE_VAL*24*40);
		
		ActualFreq = ActualFreq*10;
	}

	// if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	// {	    
		
	// }

	//TIM3->SR = (uint16_t)~(TIM_IT_CC3|TIM_IT_Update); 
    TIM_ClearITPendingBit(TIM3, TIM_IT_CC3|TIM_IT_Update); //清除中断标志位
 
}




//定时器4初始化
void TIM4_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    
    TIM_DeInit(TIM4);
    TIM_TimeBaseStructure.TIM_Period = 10000-1;	//72Mhz/10000/720=10Hz 定时100ms
    TIM_TimeBaseStructure.TIM_Prescaler = 720-1;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	
    TIM_Cmd(TIM4, ENABLE);
  
}


uint16_t SetFreq = 0;

const uint16_t BasePWM[6]={999,560,620,800,850,900};
const uint16_t spdTag[6]={0,41667,20833,8333,4167,2779};

uint16_t spdNow;

int32_t errNow=0;
int32_t errOld=0,errOld2=0,errOld3=0;
int32_t P,I,D;

uint16_t PWMValue;

const uint16_t kp = 15;
const uint16_t ki = 15;
const uint16_t kd = 15;
const uint16_t errILim = 1000;



void TIM4_IRQHandler(void)
{
	if( TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET ) 
    {
		spdNow = TIM3CH3_CAPTURE_VAL;	//当前速度
		
		errNow = spdNow - spdTag[SetFreq];	//速度差值
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

		PWMValue += (uint16_t)(kp*P+ki*I+kd*D);	//计算PWM值

		MotorPwmFlash(360);	//输出PWM波控制电机
		
		errOld = errNow;	//误差更新
		errOld2 = errOld;
		errOld3 = errOld2;

		TIM_ClearITPendingBit(TIM4, TIM_FLAG_Update);   //清除中断标志
	}	
}
