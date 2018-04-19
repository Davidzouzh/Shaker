
#include "stm32f10x.h"

#include "key.h"
#include "oled.h"
#include "pwm.h"
#include "stmflash.h"
#include "tim.h"
#include "adc.h"
#include "timer.h"




int main(void)
{
	uint32_t pwm=0,time=0,val;

	SysTick_Init();										//ϵͳʱ�Ӽ��δ�ʱ����ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//�����ж����ȼ�����2
	
	OLED_Init();
	//��ʾ ά�����Ƽ� power on..
	OLED_ShowCHinese(0,2,0,24);
	OLED_ShowCHinese(24,2,1,24);
	OLED_ShowCHinese(48,2,2,24);
	OLED_ShowCHinese(72,2,3,24);
	OLED_ShowCHinese(96,2,4,24);
	OLED_ShowString(48,6,"power on..",16);
	
	PWM_Config();
	TIM3_Config();
	TIM4_Config();
	ADC_Config();
	KEY_Config();
	
	STMFLASH_Read(STM32_FLASH_BASE+STM32_FLASH_OFFEST, &key_menu, 1);//��ȡ����һ��ֵ
	
	delay_ms(1000);
	OLED_Clear();
	
	
	while(1)
	{
	
		OLED_ShowNum(0,0,ActualFreq,6,16);
		OLED_ShowNum(0,2,BatteryVal,6,16);

		
		delay_ms(500);
		
	//�������
		Get_BatteryVal();


	}
} 

