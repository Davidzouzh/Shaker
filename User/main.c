
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
	
	Get_BatteryVal();//��ȡ��ѹֵ
	
	delay_ms(1000);
	OLED_Clear();
	
	while(BatteryVal <= 10.0)		//����������飬�͵�����������
	{
		OLED_ShowCHinese(24,3,17,24);//���͡�
		OLED_ShowCHinese(48,3,18,24);//���硱
		OLED_ShowCHinese(72,3,19,24);//������
		OLED_ShowString(96,3,"..",24);
	}
	
	OLED_ShowCHinese(12,0,5,24);//��Ƶ��
	OLED_ShowCHinese(36,0,6,24);//���ʡ�
	OLED_ShowCHinese(60,0,7,24);//���衱
	OLED_ShowCHinese(84,0,8,24);//���á�
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
	OLED_ShowCHinese(72,6,9,16);//������
	OLED_ShowCHinese(88,6,10,16);//������
	OLED_ShowCHinese(104,6,11,16);//������
	
	while(1)
	{
	//����ɨ��
		KEY_start_Scan();//ɨ����ͣ����
		if(key_start == isOFF)//�ǹ���״̬����ɨ��˵�����
		{
			KEY_menu_Scan();
		}
	
	//��ͣ����
		if(key_action == turnON)//��������
		{
			key_action = noAction;
			
			STMFLASH_Write(STM32_FLASH_BASE+STM32_FLASH_OFFEST, &key_menu, 1);//��ֵ����
			Set_Freq(key_menu);//��ֵд����ٻ�
			
			timeStart = sysTickUptime;//����ʱ��
			//ˢ��OLED
			OLED_Clear();
			OLED_ShowCHinese(0,0,5,24);//��Ƶ��
			OLED_ShowCHinese(24,0,6,24);//���ʡ�
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
			OLED_ShowCHinese(0,3,12,24);//��ʱ��
			OLED_ShowCHinese(24,3,13,24);//���䡱
			OLED_ShowString(48,3,": 0min",24);
			
			OLED_ShowCHinese(72,6,14,16);//������
			OLED_ShowCHinese(88,6,15,16);//������
			OLED_ShowCHinese(104,6,16,16);//���С�
			
			
		}
		else if(key_action == turnOFF)//ֹͣ����
		{
			key_action = noAction;
			
			Set_Freq(0);//�����ٻ�ֵ��0
			
			//ˢ��OLED
			OLED_Clear();
			delay_ms(400);
			OLED_ShowCHinese(12,0,5,24);//��Ƶ��
			OLED_ShowCHinese(36,0,6,24);//���ʡ�
			OLED_ShowCHinese(60,0,7,24);//���衱
			OLED_ShowCHinese(84,0,8,24);//���á�
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
			OLED_ShowCHinese(72,6,9,16);//������
			OLED_ShowCHinese(88,6,10,16);//������
			OLED_ShowCHinese(104,6,11,16);//������
		}
		
		
	//ˢ��OLED
		if(key_start == isON)//���ڹ���״̬
		{
			min = (sysTickUptime-timeStart)/60000;
			OLED_ShowNum(60,3,min,2,24);	//��ʾ��תʱ��
			
		}
		else//�ǹ���״̬
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
		
	//�������
		Get_BatteryVal();

		if(BatteryVal <= 10.0)		//�����ѹ����10V������Ϊ�͵����ˣ�
		{
			OLED_ShowCHinese(0,6,17,16);//���͡�
			OLED_ShowCHinese(16,6,18,16);//���硱
			OLED_ShowCHinese(32,6,19,16);//������
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

