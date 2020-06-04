#ifndef LED_H_
#define LED_H_

#include "system_foundation.h"

#define LEDNUM 4

typedef struct led_t {
	GPIO_TypeDef *port;
	_ushort pin;
}LED ;


LED Ledlist[LEDNUM] = {{GPIOD,2},
					   {GPIOD,3},
					   {GPIOD,4},
					   {GPIOD,7}
					   };
bool is_power;

void LED_Power_On(){
	RCCSwitch(204,ENABLE);
	is_power = TRUE;
}

void LED_Power_Off(){
	RCCSwitch(204,DISABLE);
	is_power = FALSE;
}

ErrorStatus LED_Init(_c_uchar _target){
	LED *targetinfo = &(Ledlist[_target-1]);
	return GPIO_Initialize(targetinfo->port, targetinfo->pin, GPIO_Speed_50MHz, GPIO_Mode_Out_PP);
	}

ErrorStatus LED_Init_ALL(){
	_uchar i;
	ErrorStatus result = ERROR;
	for (i=1;i<=LEDNUM;i++){
		result = LED_Init(i);
		}
	return result;
	}

ErrorStatus LED_DeInit(_c_uchar _target){
	LED *targetinfo = &(Ledlist[_target-1]);
	return GPIO_DeInitialze(targetinfo->port, targetinfo->pin);
}

ErrorStatus LED_DeInit_ALL(){
	_uchar i;
	ErrorStatus result = ERROR;
	for (i=1;i<=LEDNUM;i++){
		result = LED_DeInit(i);
		}
	return result;
}


ErrorStatus LED_Light_ON(_c_uchar _target){
	ErrorStatus result = ERROR;
	LED *targetinfo = &(Ledlist[_target-1]);
	if (is_power){
		GPIO_SetBits(targetinfo->port, GPIO_PIN[targetinfo->pin]);
		result = SUCCESS;
	}
	return result;
}

ErrorStatus LED_Light_ON_ALL(){
	_uchar i;
	ErrorStatus result = ERROR;
	for (i=1;i<=LEDNUM;i++){
		result = LED_Light_ON(i);
		}
	return result;
}

ErrorStatus LED_Light_OFF(_c_uchar _target){
	ErrorStatus result = ERROR;
	LED *targetinfo = &(Ledlist[_target-1]);
	if (is_power){
		GPIO_ResetBits(targetinfo->port, GPIO_PIN[targetinfo->pin]);
		result = SUCCESS;
	}
	return result;
}

ErrorStatus LED_Light_OFF_ALL(){
	_uchar i;
	ErrorStatus result = ERROR;
	for (i=1;i<=LEDNUM;i++){
		result = LED_Light_OFF(i);
		}
	return result;
}

#endif
