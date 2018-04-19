
#include "stm32f10x.h"

#include "encoder.h"
#include "key.h"
#include "oled.h"
#include "pwm.h"
#include "stmflash.h"
#include "tim.h"
#include "timer.h"




int main(void)
{
	uint32_t timeStart=0,min=0;

	SysTick_Init();										//系统时钟及滴答定时器初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//设置中断优先级分组2
	
	OLED_Init();
	//显示 维瓦拉科技 power on..
	OLED_ShowCHinese(0,2,0,24);
	OLED_ShowCHinese(24,2,1,24);
	OLED_ShowCHinese(48,2,2,24);
	OLED_ShowCHinese(72,2,3,24);
	OLED_ShowCHinese(96,2,4,24);
	OLED_ShowString(48,6,"power on..",16);
	
	TIM3_Config();
	Encoder_Config();
	PWM_Config();
	KEY_Config();
	
	STMFLASH_Read(STM32_FLASH_BASE+STM32_FLASH_OFFEST, &key_menu, 1);//读取出上一次值
	
	delay_ms(1000);
	OLED_Clear();
	OLED_ShowCHinese(12,0,5,24);
	OLED_ShowCHinese(36,0,6,24);
	OLED_ShowCHinese(60,0,7,24);
	OLED_ShowCHinese(84,0,8,24);
	//并显示
	switch(key_menu)
	{
		case 1:
			OLED_ShowString(34,3,"0.1Hz",24);
			break;
		case 2:
			OLED_ShowString(34,3,"0.2Hz",24);
			break;
		case 3:
			OLED_ShowString(34,3,"0.5Hz",24);
			break;
		case 4:
			OLED_ShowString(34,3,"1.0Hz",24);
			break;
		case 5:
			OLED_ShowString(34,3,"1.5Hz",24);
			break;
		default:
			OLED_ShowString(34,3,"? Hz",24);
			break;
	}
	OLED_ShowCHinese(72,6,9,16);
	OLED_ShowCHinese(88,6,10,16);
	OLED_ShowCHinese(104,6,11,16);
	
	
	
	while(1)
	{
	//按键扫描
		KEY_start_Scan();//扫描启停按键
		if(key_start == isOFF)//非工作状态则还需扫描菜单按键
		{
			KEY_menu_Scan();
		}
	
	//启停动作
		if(key_action == turnON)//启动动作
		{
			key_action = noAction;
			
			STMFLASH_Write(STM32_FLASH_BASE+STM32_FLASH_OFFEST, &key_menu, 1);//将值保存
			freq = key_menu;//将值写入调速环
			
			timeStart = sysTickUptime;//重置时间
			//刷新OLED
			OLED_Clear();
			OLED_ShowCHinese(0,0,5,24);
			OLED_ShowCHinese(24,0,6,24);
			switch(key_menu)
			{
				case 1:
					OLED_ShowString(48,0,":0.1Hz",24);
					break;
				case 2:
					OLED_ShowString(48,0,":0.2Hz",24);
					break;
				case 3:
					OLED_ShowString(48,0,":0.5Hz",24);
					break;
				case 4:
					OLED_ShowString(48,0,":1.0Hz",24);
					break;
				case 5:
					OLED_ShowString(48,0,":1.5Hz",24);
					break;
				default:
					OLED_ShowString(48,0,":? Hz",24);
					break;
			}
			OLED_ShowCHinese(0,3,12,24);
			OLED_ShowCHinese(24,3,13,24);
			OLED_ShowString(48,3,": 0min",24);
			
			OLED_ShowCHinese(72,6,14,16);
			OLED_ShowCHinese(88,6,15,16);
			OLED_ShowCHinese(104,6,16,16);
			
			
		}
		else if(key_action == turnOFF)//停止动作
		{
			key_action = noAction;
			freq = 0;//将调速环值置0
			//刷新OLED
			OLED_Clear();
			delay_ms(600);
			OLED_ShowCHinese(12,0,5,24);
			OLED_ShowCHinese(36,0,6,24);
			OLED_ShowCHinese(60,0,7,24);
			OLED_ShowCHinese(84,0,8,24);
			switch(key_menu)
			{
				case 1:
					OLED_ShowString(34,3,"0.1Hz",24);
					break;
				case 2:
					OLED_ShowString(34,3,"0.2Hz",24);
					break;
				case 3:
					OLED_ShowString(34,3,"0.5Hz",24);
					break;
				case 4:
					OLED_ShowString(34,3,"1.0Hz",24);
					break;
				case 5:
					OLED_ShowString(34,3,"1.5Hz",24);
					break;
				default:
					OLED_ShowString(34,3,"? Hz",24);
					break;
			}
			OLED_ShowCHinese(72,6,9,16);
			OLED_ShowCHinese(88,6,10,16);
			OLED_ShowCHinese(104,6,11,16);
		}
		
		
	//刷新OLED
		if(key_start == isON)//处于工作状态
		{
			min = (sysTickUptime-timeStart)/60000;
			OLED_ShowNum(60,3,min,2,24);
			
		}
		else//非工作状态
		{
			switch(key_menu)
			{
				case 1:
					OLED_ShowString(34,3,"0.1Hz",24);
					break;
				case 2:
					OLED_ShowString(34,3,"0.2Hz",24);
					break;
				case 3:
					OLED_ShowString(34,3,"0.5Hz",24);
					break;
				case 4:
					OLED_ShowString(34,3,"1.0Hz",24);
					break;
				case 5:
					OLED_ShowString(34,3,"1.5Hz",24);
					break;
				default:
					OLED_ShowString(34,3,"? Hz",24);
					break;
			}
		}

	}
} 

