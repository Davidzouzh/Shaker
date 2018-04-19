
#include "adc.h"

void ADC_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;

//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	//设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M,否则将导致ADC准确度下降! 

//GPIOC配置                        
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;	//模拟输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);

//ADC3配置
	ADC_DeInit(ADC1);
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//单独工作
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//关闭通道扫描
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由TIM4通道4外部触发
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC1, &ADC_InitStructure);
	//ADC1转换通道队列配置
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_28Cycles5);		//ADC1通道1，PA1
	
	ADC_Cmd(ADC1, ENABLE);	//使能ADC1
	
	ADC_ResetCalibration(ADC1);	//使能复位校准
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	ADC_StartCalibration(ADC1);	//开启AD校准
	while(ADC_GetCalibrationStatus(ADC1));	//等待校准结束

}

float BatteryVal=0.0;

void Get_BatteryVal(void)
{
	uint16_t adc;
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));		//等待转换结束
	
	adc = ADC_GetConversionValue(ADC1);
	
	BatteryVal = 13.66*adc/4096;
	//BatteryVal = 3.26*adc/4096*(15.0+4.7)/4.7;
	
	BatteryVal = BatteryVal*10;
	
}

