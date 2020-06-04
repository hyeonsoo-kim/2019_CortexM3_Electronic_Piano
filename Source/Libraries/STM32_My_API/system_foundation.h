#ifndef SYSTEM_FOUNDATION_H_INCLUDED
#define SYSTEM_FOUNDATION_H_INCLUDED


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_tim.h"

#ifdef GCC
#include "system_stm32f10x.c"
#include "stm32f10x_rcc.c"
#include "stm32f10x_gpio.c"
#include "stm32f10x_spi.c"
#include "stm32f10x_usart.c"
#include "stm32f10x_adc.c"
#include "stm32f10x_dma.c"
#include "stm32f10x_tim.c"
#endif


#define FALSE 0
#define TRUE 1

typedef GPIO_InitTypeDef GPIOinitdata;

/* =================================================================
 * Type Definitions
 * This System has VOLATILE Data type as DEFAULT.
 * This System supports integral types ( char, short, int )
 * and Following Prefix.
 *
 * Typename : [volatile option][const][sign option]{char, short, int}
 *
 * # Volatile options
 *   (1) Noting : Volatile, as default
 *   (2) _nv	: None-Volatile
 *
 * # Const option : If you want use const type, append '_c'.
 *
 * # Sign options
 *   (1) _s : signed
 *   (2) _u : unsigned
 * =================================================================
 */
typedef vs8  _schar     ;
typedef vs16 _sshort    ;
typedef vs32 _sint      ;

typedef vsc8  _c_schar  ;
typedef vsc16 _c_sshort ;
typedef vsc32 _c_sint   ;

typedef vu8   _uchar    ;
typedef vu16  _ushort   ;
typedef vu32  _uint     ;

typedef vuc8  _c_uchar  ;
typedef vuc16 _c_ushort ;
typedef vuc32 _c_uint   ;

typedef s8  _nv_schar     ;
typedef s16 _nv_sshort    ;
typedef s32 _nv_sint      ;

typedef sc8  _c_nv_schar  ;
typedef sc16 _c_nv_sshort ;
typedef sc32 _c_nv_sint   ;

typedef u8   _nv_uchar    ;
typedef u16  _nv_ushort   ;
typedef u32  _nv_uint     ;

typedef uc8  _c_nv_uchar  ;
typedef uc16 _c_nv_ushort ;
typedef uc32 _c_nv_uint   ;

// ===================================================================================

/* ===================================================================================
 * System Initialize
 *
 */

ErrorStatus sysState = ERROR;

ErrorStatus board_initlize(){
    SystemInit();
    return SUCCESS;
    }

ErrorStatus SysBoot() {
	sysState = board_initlize();
    //sysState &= lcdon();
    return SUCCESS;
    }

/* ===================================================================================
 * RCC Initilize
 *
 */

#define RCC_Device_categorynum 3
#define RCC_AHB_numofPort  9
#define RCC_APB1_numofPort 22
#define RCC_APB2_numofPort 21


_uint RCC_AHB_DEV[9] = { RCC_AHBPeriph_DMA1      , RCC_AHBPeriph_DMA2      ,
                        RCC_AHBPeriph_SRAM      , RCC_AHBPeriph_FLITF     ,
                        RCC_AHBPeriph_CRC       , RCC_AHBPeriph_OTG_FS    ,
                        RCC_AHBPeriph_ETH_MAC   , RCC_AHBPeriph_ETH_MAC_Tx,
                        RCC_AHBPeriph_ETH_MAC_Rx
                        };

_uint RCC_APB1_DEV[22] = { RCC_APB1Periph_TIM2  , RCC_APB1Periph_TIM3  , RCC_APB1Periph_TIM4 ,
                          RCC_APB1Periph_TIM5  , RCC_APB1Periph_TIM6  , RCC_APB1Periph_TIM7 ,
                          RCC_APB1Periph_WWDG  , RCC_APB1Periph_SPI2  , RCC_APB1Periph_SPI3 ,
                          RCC_APB1Periph_USART2, RCC_APB1Periph_USART3, RCC_APB1Periph_I2C1 ,
                          RCC_APB1Periph_I2C2  , RCC_APB1Periph_USB   , RCC_APB1Periph_CAN1 ,
                          RCC_APB1Periph_BKP   , RCC_APB1Periph_PWR   , RCC_APB1Periph_DAC  ,
                          RCC_APB1Periph_CEC   , RCC_APB1Periph_TIM12 , RCC_APB1Periph_TIM13,
                          RCC_APB1Periph_TIM14
                          };

_uint RCC_APB2_DEV[21] = { RCC_APB2Periph_AFIO, RCC_APB2Periph_GPIOA, RCC_APB2Periph_GPIOB,
                              RCC_APB2Periph_GPIOC, RCC_APB2Periph_GPIOD, RCC_APB2Periph_GPIOE,
                              RCC_APB2Periph_GPIOF, RCC_APB2Periph_GPIOG, RCC_APB2Periph_ADC1,
                              RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
                              RCC_APB2Periph_TIM8, RCC_APB2Periph_USART1, RCC_APB2Periph_ADC3,
                              RCC_APB2Periph_TIM15, RCC_APB2Periph_TIM16, RCC_APB2Periph_TIM17,
                              RCC_APB2Periph_TIM9, RCC_APB2Periph_TIM10, RCC_APB2Periph_TIM11
                            };


// 200 ; AFIO, 201 ; GPIOA


_uint RCC_status[3] = {0,0,0};

ErrorStatus RCCrefresh () {
    _uchar i;
    for (i = 0; i< 3 ; i++) {
    	RCC_status[i] = 0;
    }
    RCC_DeInit();
    return SUCCESS;
    }

ErrorStatus RCC_Off(const _uchar code) {
    _uchar is_valid = (code < RCC_Device_categorynum);
    ErrorStatus result = ERROR;
    if (is_valid) {
        switch(code) {
        case 0:
            RCC_AHBPeriphClockCmd( RCC_status[code], DISABLE); break;
        case 1:
            RCC_APB1PeriphClockCmd( RCC_status[code], DISABLE); break;
        case 2:
            RCC_APB2PeriphClockCmd( RCC_status[code], DISABLE); break;
        default: break;
        }
        RCC_status[code] = 0;
        result=SUCCESS;
    }
    return result;
    }

_uint RCC_Devicecode_is_valid(const _uchar code) {
    _uchar _category = code / 100 ;
    _uchar _portcode = code % 100 ;
    _uchar bool_check = 0;
    switch(_category) {
        case 0: bool_check = (_portcode <= RCC_AHB_numofPort); break;
        case 1: bool_check = (_portcode <= RCC_APB1_numofPort); break;
        case 2: bool_check = (_portcode <= RCC_APB2_numofPort); break;
        default: break;
        }
    return bool_check;
    }

ErrorStatus RCCSwitch (_c_ushort code, const FunctionalState _state ) {
    //code parsing
    _ushort _category = code / 100 ;
    _ushort _portcode = code % 100 ;
    _uint target = 0;
    _uint *RCC_device_list[3] = {RCC_AHB_DEV, RCC_APB1_DEV, RCC_APB2_DEV};

    if (_category > 2)
        return ERROR;

    target = RCC_device_list[_category][_portcode];

    switch(_category) {
        case 0:
            RCC_AHBPeriphClockCmd(target, _state) ; break;
        case 1:
            RCC_APB1PeriphClockCmd(target, _state); break;
        case 2:
            RCC_APB2PeriphClockCmd(target, _state); break;
        }
    if (_state == ENABLE) RCC_status[_category] |= target;
    else RCC_status[_category] |= ~target;
    return SUCCESS;
    }

uint16_t GPIO_PIN[16] = {GPIO_Pin_0 , GPIO_Pin_1 , GPIO_Pin_2 , GPIO_Pin_3 ,
						 GPIO_Pin_4 , GPIO_Pin_5 , GPIO_Pin_6 , GPIO_Pin_7 ,
						 GPIO_Pin_8 , GPIO_Pin_9 , GPIO_Pin_10, GPIO_Pin_11,
						 GPIO_Pin_12, GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15
					 	 };



ErrorStatus GPIO_Initialize(GPIO_TypeDef* _port, _c_ushort _pinnum, GPIOSpeed_TypeDef _speed, GPIOMode_TypeDef _mode){
	ErrorStatus result = ERROR;
	_uchar is_valid = (_port <= GPIOG ) && (_pinnum < 16);
	GPIOinitdata _data;

	_data.GPIO_Pin = GPIO_PIN[_pinnum];
	_data.GPIO_Speed = _speed;
	_data.GPIO_Mode =  _mode;

	if(is_valid){
		GPIO_Init(_port, &_data);
		result = SUCCESS;
	}

	return result;
	}

ErrorStatus GPIO_DeInitialze(GPIO_TypeDef* _port, _c_ushort _pinnum){
	return GPIO_Initialize(_port, GPIO_PIN[_pinnum], GPIO_Speed_2MHz, GPIO_Mode_IN_FLOATING);
}

void Delay(_c_uint _time){
	_uint i = 0;
	for (i = 0; i< _time *1000000 ; i++){;}
}

#endif // SYSTEM_FOUNDATION_H_INCLUDED
