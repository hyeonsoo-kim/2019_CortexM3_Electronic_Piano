#ifndef API_H_INCLUDEED
#define API_H_INCLUDEED

#include "system_foundation.h"
#include "display.h"
#include "interrupt.h"
#include "led.h"
#include "adc.h"
#include "dma.h"

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

/*
 * Keyboard Input Calibration Data
 */
bool getborder = false;

_uint ADC_DualConvertedValueTab[12] = {0,};
_uint ADC_DualConvertedBorder[12] = {0,};

void getcalibration(){
	if(!getborder){
		for (_uchar i = 0; i< 12; i++){
				 ADC_DualConvertedBorder[i] = ADC_DualConvertedValueTab[i];
			}
		getborder = true;
		}
}

/*
 * Scale Frequency datas
 */

typedef struct
{
   _nv_ushort prescaler;
   _nv_ushort period;
} timer_frq;

timer_frq graceful_scale_timer[108] =
{
   { 49,44931} ,{157,13236} ,{101,19420} ,{ 34,54451} ,{ 89,19634} ,{ 43,38357} ,{ 49,31771} ,{211, 6964} ,{101,13732} ,{109,12010} ,{ 41,30137} ,{347, 3361}
  ,{ 41,26849} ,{157, 6618} ,{101, 9710} ,{ 17,54451} ,{ 89, 9817} ,{ 25,32987} ,{ 23,33843} ,{211, 3482} ,{101, 6866} ,{109, 6005} ,{ 12,51484} ,{257, 2269}
  ,{  9,61156} ,{157, 3309} ,{101, 4855} ,{ 37,12509} ,{  7,62408} ,{ 41,10057} ,{ 13,29938} ,{211, 1741} ,{101, 3433} ,{  8,40909} ,{  6,51484} ,{ 11,26506}
  ,{  6,45867} ,{  4,64939} ,{  4,61294} ,{  4,57854} ,{  4,54607} ,{  4,51542} ,{ 13,14969} ,{  3,61225} ,{ 17,10198} ,{  4,40909} ,{  3,51484} ,{ 11,13253}
  ,{  3,45867} ,{  2,64939} ,{  2,61294} ,{  2,57854} ,{  2,54607} ,{  2,51542} ,{  2,48649} ,{  2,45918} ,{ 17, 5099} ,{  2,40909} ,{  2,38613} ,{  3,24297}
  ,{  2,34400} ,{  7, 9277} ,{  2,30647} ,{  2,28927} ,{  7, 7801} ,{  2,25771} ,{  2,24324} ,{  2,22959} ,{  3,14447} ,{ 11, 3719} ,{  3,12871} ,{  5, 7289}
  ,{  2,17200} ,{  3,10823} ,{ 19, 1613} ,{  2,14463} ,{  3, 9101} ,{  2,12885} ,{  2,12162} ,{  3, 7653} ,{  2,10835} ,{  2,10227} ,{  2, 9653} ,{  2, 9111}
  ,{  2, 8600} ,{  2, 8117} ,{  7, 2189} ,{  3, 4821} ,{ 11, 1241} ,{  3, 4295} ,{  2, 6081} ,{ 13,  883} ,{  5, 2167} ,{  3, 3409} ,{  7, 1379} ,{  3, 3037}
  ,{  2, 4300} ,{  2, 4058} ,{ 47,  163} ,{  7, 1033} ,{  3, 2275} ,{  2, 3221} ,{  3, 2027} ,{  3, 1913} ,{  2, 2708} ,{  2, 2556} ,{  2, 2413} ,{  5,  911}
};

#endif
