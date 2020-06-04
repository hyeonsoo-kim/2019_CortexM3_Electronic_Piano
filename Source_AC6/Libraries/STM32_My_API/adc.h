/*
 * adc.h
 *
 *  Created on: 2019. 12. 12.
 *      Author: Team03
 */

#ifndef ADC_H_
#define ADC_H_

#include "system_foundation.h"

typedef ADC_InitTypeDef ADCinitdata;


typedef struct _ADCChannelInfo{
	_nv_uchar channelnum;
	GPIO_TypeDef *port;
	_uchar pin;
	GPIOSpeed_TypeDef speed;
	GPIOMode_TypeDef mode;
}ADCChannelInfo;

typedef struct _ADCInfo{
	ADC_TypeDef* _adc;
	_nv_uint ADC_Mode;
	FunctionalState ADC_ScanConvMode;
	FunctionalState ADC_ContinuousConvMode;
	_nv_uint ADC_ExternalTrigConv;
	_nv_uint ADC_DataAlign;
	_nv_uchar ADC_NbrOfChannel;
	ADCChannelInfo *list;
	_uchar nofport;
} ADCInfo;

_uchar ADC_RCCCode[3] = {208,209,214};

ErrorStatus ADC_PowerON(_c_uchar n){
	return RCCSwitch(ADC_RCCCode[n-1],ENABLE);
}

ErrorStatus ADC_PowerOFF(_c_uchar n){
	return RCCSwitch(ADC_RCCCode[n-1],DISABLE);
}

ErrorStatus ADC_Initialize( ADCInfo *info ){
	ErrorStatus result = ERROR;
	_uchar i;
	ADCChannelInfo* list = NULL;
	if(info->nofport >0 && info->list){
		list = info->list;
		for (i = 0; i< info->nofport ;i++){
			result = GPIO_Initialize(list[i].port, list[i].pin, list[i].speed, list[i].mode);
		}
	}
	if(info->_adc){

		ADCinitdata _data = {
				info->ADC_Mode,
				info->ADC_ScanConvMode,
				info->ADC_ContinuousConvMode,
				info->ADC_ExternalTrigConv,
				info->ADC_DataAlign,
				info->ADC_NbrOfChannel
		};

		ADC_Init(info->_adc,&_data);
		result &= SUCCESS;
	}
	else result &=ERROR;

	return result;
}

ErrorStatus ADC_Multiple_Regcfg(ADCInfo *info){
	ErrorStatus result = ERROR;
	_uchar i;
	ADCChannelInfo* list = NULL;
	if(info->nofport >0 && info->list){
			list = info->list;
			for (i = 0; i< info->nofport ;i++){
				ADC_RegularChannelConfig(info->_adc, list[i].channelnum, i+1,ADC_SampleTime_239Cycles5);
			}
			result = SUCCESS;
		}
	return result;
}

ErrorStatus ADC_IntrruptSwitch(ADC_TypeDef* _adc, uint16_t ADC_IT, FunctionalState NewState){
	ErrorStatus result = ERROR;
	if (_adc) {
		ADC_ITConfig(_adc, ADC_IT, NewState);
		result = SUCCESS;
	}
	return result;
}


ErrorStatus ADC_ON(ADC_TypeDef* _adc){
	ADC_Cmd(_adc,ENABLE);
	return SUCCESS;
}

ErrorStatus ADC_DataCalibration(ADC_TypeDef* _adc){
	ErrorStatus result = ERROR;
	ADC_ResetCalibration(_adc);
	while(ADC_GetResetCalibrationStatus(_adc)){;}
	ADC_StartCalibration(_adc);
	while(ADC_GetCalibrationStatus(_adc)){;}
	result = SUCCESS;
	return result;
}

#endif /* ADC_H_ */
