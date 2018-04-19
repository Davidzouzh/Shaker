
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

uint16_t Queue_CAPTURE[10];
uint8_t queueNum=0;
uint32_t TIM3CH3_CAPTURE_VAL=0;	//输入捕获值
//1us记一次，一次溢出要记65536us，即65ms，电机的最慢转速0.1HZ也是最久41ms一次捕获
//电机最快转速1.5HZ，一次捕获约2.7ms

float ActualFreq;

void TIM3_IRQHandler(void)
{
	uint8_t i;
	if (TIM_GetITStatus(TIM3, TIM_IT_CC3) != RESET)//捕获3发生捕获事件
	{	
		Queue_CAPTURE[queueNum++] = TIM3->CCR3;
		if(queueNum>=10)
			queueNum=0;
		for(i=0;i<10;i++)
		{
			TIM3CH3_CAPTURE_VAL += Queue_CAPTURE[i];
		}	
		TIM3CH3_CAPTURE_VAL /= 10;
		
		//TIM3CH3_CAPTURE_VAL = TIM_GetCapture3(TIM3);
		TIM3->CNT = 0;
		//TIM_SetCounter(TIM3,0);
		
		ActualFreq = 1000000.0/(TIM3CH3_CAPTURE_VAL*24*65);
		
		//ActualFreq = ActualFreq*10;
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
    TIM_TimeBaseStructure.TIM_Period = 2000-1;	//72Mhz/2000/720=50Hz 定时20ms
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


uint8_t Freq_Num = 0;

const uint16_t BasePWM[12]={0,160,210,260,310,360,410,460,510,560,625,660};
const float DesiredFreq[12]={0,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.12,1.2};

float errNow=0;
float errOld=0,errOld2=0,errOld3=0;
float P,I,D;

const float kp = 150.0;
const float ki = 80.0;
const float kd = 150.0;
const float errILim = 1000.0;

uint16_t PWMValue=0;

void TIM4_IRQHandler(void)
{
	if( TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET ) 
    {
		if(key_start == isON)
		{
			errNow = DesiredFreq[Freq_Num] - ActualFreq;	//速度差值
		
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

			PWMValue += (int32_t)(kp*P+ki*I+kd*D);	//计算PWM值

			MotorPwmFlash(PWMValue);	//输出PWM波控制电机
			
			errOld = errNow;	//误差更新
			errOld2 = errOld;
			errOld3 = errOld2;
		}
		else
		{
			MotorPwmFlash(0);
		}

		TIM_ClearITPendingBit(TIM4, TIM_FLAG_Update);   //清除中断标志
	}	
}



void Set_Freq(uint8_t freq)
{
	uint8_t i;
	
	Freq_Num = freq;	//设置工作频率和基础PMW值
	PWMValue = BasePWM[freq];
	
	ActualFreq = DesiredFreq[freq];	//清除上一次运转遗留的值
	for(i=0;i<10;i++)
		Queue_CAPTURE[i]=0;
	
	errNow=0;
	errOld = 0;
	errOld2 = 0;
	errOld3 = 0;

}


