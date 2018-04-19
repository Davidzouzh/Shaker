#ifndef PWM__
#define PWM__

#include "stm32f10x.h"


#define Moto_PwmMax 999



void PWM_Config(void);

void MotorPwmFlash(int16_t MOTO_PWM);




#endif

