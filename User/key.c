

#include "key.h"
#include "timer.h"

void KEY_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//设置成上拉输入
 	GPIO_Init(GPIOA, &GPIO_InitStructure);

} 

uint8_t key_start=isOFF;
uint8_t key_action=noAction;
uint16_t key_menu=1;


void KEY_start_Scan(void)
{
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == RESET)
	{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == RESET)
		{
			if(key_start == isOFF)
			{
				key_start = isON;
				key_action = turnON;
				return;
			}	
			else
			{
				key_start = isOFF;
				key_action = turnOFF;
				return;
			}
		}
	}
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == RESET);
	key_action = noAction;
}


void KEY_menu_Scan(void)
{
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == RESET)
		{
			key_menu++;
			if(key_menu >5)
				key_menu = 1;
		}
	}
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == RESET);
}

