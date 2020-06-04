#ifndef API_H_INCLUDEED
#define API_H_INCLUDEED

#include "system_foundation.h"
#include "display.h"
#include "interrupt.h"
#include "led.h"
#include "adc.h"


ADCChannelInfo ADC1ChannelConfiglist[12] = {
{0,GPIOA,0,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{1,GPIOA,1,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{2,GPIOA,2,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{3,GPIOA,3,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{4,GPIOA,4,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{5,GPIOA,5,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{6,GPIOA,6,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{7,GPIOA,7,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{8,GPIOB,0,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{9,GPIOB,1,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{10,GPIOC,0,GPIO_Speed_50MHz,GPIO_Mode_AIN},
{11,GPIOC,1,GPIO_Speed_50MHz,GPIO_Mode_AIN}
};

ADCInfo ADC_1 = {
		ADC1,
		ADC_Mode_Independent,
		ENABLE,
		ENABLE,
		ADC_ExternalTrigConv_None,
		ADC_DataAlign_Right,
		12,
		ADC1ChannelConfiglist,
		12
};

#endif
