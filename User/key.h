#ifndef KEY__
#define KEY__

#include "stm32f10x.h"

#define isON	1
#define isOFF	0

#define noAction	0
#define turnON		1
#define turnOFF		2


extern uint8_t key_start;
extern uint8_t key_action;
extern uint16_t key_menu;

void KEY_Config(void);

void KEY_start_Scan(void);
void KEY_menu_Scan(void);

#endif

