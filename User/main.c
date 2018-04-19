
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
	uint32_t timeStart=0,min=0,powerFlashtime=0;
	
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
	
	PWM_Config();
	TIM3_Config();
	TIM4_Config();
	ADC_Config();
	KEY_Config();
	
	STMFLASH_Read(STM32_FLASH_BASE+STM32_FLASH_OFFEST, &key_menu, 1);//读取出上一次值
	
	Get_BatteryVal();//读取电压值
	
	delay_ms(1000);
	OLED_Clear();
	
	while(BatteryVal <= 10.0)		//开机电量检查，低电量则不允许工作
	{
		OLED_ShowCHinese(24,3,17,24);//“低”
		OLED_ShowCHinese(48,3,18,24);//“电”
		OLED_ShowCHinese(72,3,19,24);//“量”
		OLED_ShowString(96,3,"..",24);
	}
	
	OLED_ShowCHinese(12,0,5,24);//“频”
	OLED_ShowCHinese(36,0,6,24);//“率”
	OLED_ShowCHinese(60,0,7,24);//“设”
	OLED_ShowCHinese(84,0,8,24);//“置”
	switch(key_menu)
	{
		case 1:
			OLED_ShowString(34,3,"0.2Hz",24);
			break;
		case 2:
			OLED_ShowString(34,3,"0.3Hz",24);
			break;
		case 3:
			OLED_ShowString(34,3,"0.4Hz",24);
			break;
		case 4:
			OLED_ShowString(34,3,"0.5Hz",24);
			break;
		case 5:
			OLED_ShowString(34,3,"0.6Hz",24);
			break;
		case 6:
			OLED_ShowString(34,3,"0.7Hz",24);
			break;
		case 7:
			OLED_ShowString(34,3,"0.8Hz",24);
			break;
		case 8:
			OLED_ShowString(34,3,"0.9Hz",24);
			break;
		case 9:
			OLED_ShowString(34,3,"1.0Hz",24);
			break;
		case 10:
			OLED_ShowString(34,3,"1.1Hz",24);
			break;
		case 11:
			OLED_ShowString(34,3,"1.2Hz",24);
			break;
		default:
			OLED_ShowString(34,3,"? Hz",24);
			break;
	}
	OLED_ShowCHinese(72,6,9,16);//“待”
	OLED_ShowCHinese(88,6,10,16);//“启”
	OLED_ShowCHinese(104,6,11,16);//“动”
	
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
			Set_Freq(key_menu);//将值写入调速环
			
			timeStart = sysTickUptime;//重置时间
			//刷新OLED
			OLED_Clear();
			OLED_ShowCHinese(0,0,5,24);//“频”
			OLED_ShowCHinese(24,0,6,24);//“率”
			switch(key_menu)
			{
				case 1:
					OLED_ShowString(48,0,":0.2Hz",24);
					break;
				case 2:
					OLED_ShowString(48,0,":0.3Hz",24);
					break;
				case 3:
					OLED_ShowString(48,0,":0.4Hz",24);
					break;
				case 4:
					OLED_ShowString(48,0,":0.5Hz",24);
					break;
				case 5:
					OLED_ShowString(48,0,":0.6Hz",24);
					break;
				case 6:
					OLED_ShowString(48,0,":0.7Hz",24);
					break;
				case 7:
					OLED_ShowString(48,0,":0.8Hz",24);
					break;
				case 8:
					OLED_ShowString(48,0,":0.9Hz",24);
					break;
				case 9:
					OLED_ShowString(48,0,":1.0Hz",24);
					break;
				case 10:
					OLED_ShowString(48,0,":1.1Hz",24);
					break;
				case 11:
					OLED_ShowString(48,0,":1.2Hz",24);
					break;
				default:
					OLED_ShowString(48,0,":? Hz",24);
					break;
			}
			OLED_ShowCHinese(0,3,12,24);//“时”
			OLED_ShowCHinese(24,3,13,24);//“间”
			OLED_ShowString(48,3,": 0min",24);
			
			OLED_ShowCHinese(72,6,14,16);//“工”
			OLED_ShowCHinese(88,6,15,16);//“作”
			OLED_ShowCHinese(104,6,16,16);//“中”
			
			
		}
		else if(key_action == turnOFF)//停止动作
		{
			key_action = noAction;
			
			Set_Freq(0);//将调速环值置0
			
			//刷新OLED
			OLED_Clear();
			delay_ms(400);
			OLED_ShowCHinese(12,0,5,24);//“频”
			OLED_ShowCHinese(36,0,6,24);//“率”
			OLED_ShowCHinese(60,0,7,24);//“设”
			OLED_ShowCHinese(84,0,8,24);//“置”
			switch(key_menu)
			{
				case 1:
					OLED_ShowString(34,3,"0.2Hz",24);
					break;
				case 2:
					OLED_ShowString(34,3,"0.3Hz",24);
					break;
				case 3:
					OLED_ShowString(34,3,"0.4Hz",24);
					break;
				case 4:
					OLED_ShowString(34,3,"0.5Hz",24);
					break;
				case 5:
					OLED_ShowString(34,3,"0.6Hz",24);
					break;
				case 6:
					OLED_ShowString(34,3,"0.7Hz",24);
					break;
				case 7:
					OLED_ShowString(34,3,"0.8Hz",24);
					break;
				case 8:
					OLED_ShowString(34,3,"0.9Hz",24);
					break;
				case 9:
					OLED_ShowString(34,3,"1.0Hz",24);
					break;
				case 10:
					OLED_ShowString(34,3,"1.1Hz",24);
					break;
				case 11:
					OLED_ShowString(34,3,"1.2Hz",24);
					break;
				default:
					OLED_ShowString(34,3,"? Hz",24);
					break;
			}
			OLED_ShowCHinese(72,6,9,16);//“待”
			OLED_ShowCHinese(88,6,10,16);//“启”
			OLED_ShowCHinese(104,6,11,16);//“动”
		}
		
		
	//刷新OLED
		if(key_start == isON)//处于工作状态
		{
			min = (sysTickUptime-timeStart)/60000;
			OLED_ShowNum(60,3,min,2,24);	//显示运转时间
			
		}
		else//非工作状态
		{
			switch(key_menu)
			{
				case 1:
					OLED_ShowString(34,3,"0.2Hz",24);
					break;
				case 2:
					OLED_ShowString(34,3,"0.3Hz",24);
					break;
				case 3:
					OLED_ShowString(34,3,"0.4Hz",24);
					break;
				case 4:
					OLED_ShowString(34,3,"0.5Hz",24);
					break;
				case 5:
					OLED_ShowString(34,3,"0.6Hz",24);
					break;
				case 6:
					OLED_ShowString(34,3,"0.7Hz",24);
					break;
				case 7:
					OLED_ShowString(34,3,"0.8Hz",24);
					break;
				case 8:
					OLED_ShowString(34,3,"0.9Hz",24);
					break;
				case 9:
					OLED_ShowString(34,3,"1.0Hz",24);
					break;
				case 10:
					OLED_ShowString(34,3,"1.1Hz",24);
					break;
				case 11:
					OLED_ShowString(34,3,"1.2Hz",24);
					break;
				default:
					OLED_ShowString(34,3,"? Hz",24);
					break;
			}
		}
		
	//电量监测
		Get_BatteryVal();

		if(BatteryVal <= 10.0)		//如果电压低于10V，则认为低电量了，
		{
			OLED_ShowCHinese(0,6,17,16);//“低”
			OLED_ShowCHinese(16,6,18,16);//“电”
			OLED_ShowCHinese(32,6,19,16);//“量”
			OLED_ShowString(48,6,"..",16);
		}
		
		if( (millis() - powerFlashtime) > 1000)
		{
			powerFlashtime = millis();
			OLED_ShowNum(0,6,BatteryVal*100,4,16);
			OLED_ShowNum(40,6,ActualFreq*100,3,16);
		}
		
		
	}

} 

