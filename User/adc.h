#ifndef ADC__
#define ADC__

#include "stm32f10x.h"

extern float BatteryVal;

void ADC_Config(void);
void Get_BatteryVal(void);


#endif

