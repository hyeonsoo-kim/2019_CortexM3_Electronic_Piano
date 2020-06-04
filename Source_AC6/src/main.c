#include "api.h"
#define MAXIMUM 256
uint16_t press;
ErrorStatus Keyboard_On(void);
ErrorStatus operating_system(void);
void PlayOn(void);
extern _uint ADC_DualConvertedValueTab[12];
extern _uint ADC_DualConvertedBorder[12];

_uint current_time = 0;
_uint running_time = 0;

void time_rewind() {
	current_time = 0;
}

typedef struct _note {
	_uint start_time;
	_uint end_time;
	_schar scale_idx;
} Note;

_schar memnotes[MAXIMUM];

_uint totaltime = 0U;

bool is_recoding = false;

typedef TIM_TimeBaseInitTypeDef TIMERinitdata;

void Timer_Configure(void) {
	TIMERinitdata _data;
	_data.TIM_ClockDivision = TIM_CKD_DIV1;
	_data.TIM_CounterMode = TIM_CounterMode_Up;
	_data.TIM_Period = 1000;
	_data.TIM_Prescaler = 7200;
	_data.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &_data);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void) {
	if (is_recoding) {
		totaltime++;
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}

ErrorStatus Boot() {
	ErrorStatus result = ERROR;
	result = SysBoot();
	result &= lcdon();
	result &= RCCSwitch(200, ENABLE);
	result &= RCCSwitch(201, ENABLE);
	result &= RCCSwitch(202, ENABLE);
	result &= RCCSwitch(203, ENABLE);
	result &= ADC_PowerON(1);
	result &= Keyboard_On();
	result &= RCCSwitch(0, ENABLE);
	result &= RCCSwitch(208, ENABLE);
	result &= DMA_Initialize(
	DMA1_Channel1, (uint32_t) &ADC1->DR, (uint32_t) ADC_DualConvertedValueTab,
	DMA_DIR_PeripheralSRC, 12,
	DMA_PeripheralInc_Disable,
	DMA_MemoryInc_Enable,
	DMA_PeripheralDataSize_Word,
	DMA_MemoryDataSize_Word,
	DMA_Mode_Circular,
	DMA_Priority_High,
	DMA_M2M_Disable);

	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);
	DMA_Cmd(DMA1_Channel1, ENABLE); //Enable the DMA1 - Channel1
	result &= NVIC_Register(DMA1_Channel1_IRQn, ENABLE, 0, 0);
	if (result) {
		LCD_ShowString(50, 50, (_nv_uchar*) "Boot Completed!", WHITE, BLACK);
#ifdef DEBUG
		LCD_ShowString(50, 66, (_nv_uchar*) "IN Key DEBUG MODE!", YELLOW,
				BLACK);
#endif
	} else
		LCD_ShowString(50, 50, (_nv_uchar*) "Error! Please Check!", WHITE,
		BLACK);
	return result;
}

extern ADCInfo ADC_1;

ErrorStatus Keyboard_On() {
	ErrorStatus result = ERROR;
	result = ADC_Initialize(&ADC_1);
	if (result) {
		result &= ADC_Multiple_Regcfg(&ADC_1);
		result &= ADC_ON(ADC1);
		result &= ADC_DataCalibration(ADC1);
		ADC_DMACmd(ADC1, ENABLE);
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	}
	return result;
}

void PlayOn() {
	TIM_Cmd(TIM4, ENABLE);
}

void PlayOff() {
	TIM_Cmd(TIM4, DISABLE);
}

extern timer_frq graceful_scale_timer[108];

_uchar octave = 3;
timer_frq *scale = NULL;

ErrorStatus operating_system() {
	GPIO_Initialize(GPIOB, 8, GPIO_Speed_50MHz, GPIO_Mode_AF_PP);
	RCCSwitch(102, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	scale = &(graceful_scale_timer[octave * 12]);
	for (int i = 0; i < 12; i++) {

		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
		TIM_TimeBaseStructure.TIM_Period = scale[i].period - 1;
		TIM_TimeBaseStructure.TIM_Prescaler = scale[i].prescaler - 1;
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

		TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
		TIM_OCInitTypeDef OC;
		OC.TIM_OCMode = TIM_OCMode_PWM1;
		OC.TIM_OCPolarity = TIM_OCPolarity_High;
		OC.TIM_OutputState = TIM_OutputState_Enable;
		OC.TIM_Pulse = 1000;

		TIM_OC3Init(TIM4, &OC);

		TIM_ARRPreloadConfig(TIM4, ENABLE);
		TIM4->EGR = TIM_PSCReloadMode_Immediate;
		TIM_Cmd(TIM4, ENABLE);
		Delay(1);
	}
	PlayOff();
	return SUCCESS;
}

bool semaphore = false;

void Playscale(_uchar idx) {

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseStructure.TIM_Period = scale[idx].period - 1;
	TIM_TimeBaseStructure.TIM_Prescaler = scale[idx].prescaler - 1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	PlayOn();
}

ErrorStatus RecordMode() {
	LCD_Clear(WHITE);
	_uint j = 0;
	LCD_ShowString(40, 30, "Record Mode", BLACK, WHITE);
	LCD_ShowSizedString(40, 60, " A# + B = Exit", 16, BLACK, WHITE);
	while (1) {
		if (!interrupt_semaphore) {
			for (_uchar i = 0; i < 12; i++) {
				ADC_DualConvertedValueTab[i] -= ADC_DualConvertedBorder[i];
				if ((_sint) ADC_DualConvertedValueTab[i] < 0)
					ADC_DualConvertedValueTab[i] = 0;
				else if (ADC_DualConvertedValueTab[i] >= 400
						&& ADC_DualConvertedValueTab[i] <= 2000) {
					if (i == 10 && ADC_DualConvertedValueTab[11] >= 400
							&& ADC_DualConvertedValueTab[11] <= 2000) {
						memnotes[j % MAXIMUM] = -2;
						return SUCCESS;
					} else
						semaphore = true;
				}

				if (semaphore) {
					memnotes[j % MAXIMUM] = i;
					Playscale(i);
					Delay(1);
					PlayOff();
					j++;
					getborder = semaphore;
					semaphore = false;
				}
			}
		}
	}
	return SUCCESS;
}

ErrorStatus OnlyPlayMode() {
	LCD_Clear(WHITE);
	_uint j = 0;
	_uint len = 0;
#ifdef DEMO
	_schar memnotes[30] = {4,2,0,2,4,4,4,2,2,2,4,4,4,4,2,0,2,4,4,4,2,2,4,2,0,-2};
#endif
	while (j < MAXIMUM) {
		if (memnotes[j] == -2)
			break;
		else
			len++;
		j++;
	}
	j = 0;
	LCD_ShowString(30, 30, "Playing Music in Memory...", BLACK, WHITE);
	LCD_ShowSizedString(40, 60, " A# + B = Exit", 16, BLACK, WHITE);

	while (j < MAXIMUM) {
		LCD_ShowNum(30, 80, j, 3, BLACK, WHITE);
		LCD_ShowChar(80, 80, '/', 16, BLACK, WHITE);
		LCD_ShowNum(100, 80, len, 3, BLACK, WHITE);
		LCD_DrawLine(25, 100, 25 + (200 * ((float)j / len)), 100);
		if (memnotes[j] == -2)
			break;
		else {
			if (memnotes[j] != -1)
				Playscale(memnotes[j]);
		}
		Delay(1);
		PlayOff();
		j++;
	}
	return SUCCESS;
}

ErrorStatus IDLE() {
	LCD_Clear(WHITE);

#ifdef DEBUG
#ifndef DEMO
	LCD_ShowString(40, 30, "KeyBoard Debug Mode", BLACK, WHITE);
	LCD_DrawLine(25, 48, 200, 48);
	LCD_ShowString(30, 50, "Num Press Calibration", BLACK, WHITE);
	LCD_DrawLine(25, 68, 200, 68);
	LCD_DrawLine(25, 262, 200, 262);
	char* key[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A",
		"A#", "B"};
#endif
#endif
	while (1) {
		LCD_ShowSizedString(40, 10, "EMBEDED PIANO", 18, BLACK, WHITE);
		LCD_ShowSizedString(40, 40, "USAGE", 16, BLACK, WHITE);
		LCD_ShowSizedString(40, 60, "C# + C = Record", 16, BLACK, WHITE);
		LCD_ShowSizedString(40, 78, "C# + D = Play Music", 16, BLACK, WHITE);
		LCD_ShowSizedString(40, 96, "D# + E = Octave Up", 16, BLACK, WHITE);
		LCD_ShowSizedString(40, 110, "D# + F = Octave Down", 16, BLACK, WHITE);
#ifdef DEMO
		LCD_ShowSizedString(40, 150, "DEMO MODE!", 16, BLUE, WHITE);
#endif
		if (!interrupt_semaphore) {
			for (_uchar i = 0; i < 12; i++) {
				ADC_DualConvertedValueTab[i] -= ADC_DualConvertedBorder[i];
				if ((_sint) ADC_DualConvertedValueTab[i] < 0)
					ADC_DualConvertedValueTab[i] = 0;
				else if (ADC_DualConvertedValueTab[i] >= 400
						&& ADC_DualConvertedValueTab[i] <= 2000) {
					if (i == 1 && ADC_DualConvertedValueTab[0] >= 400
							&& ADC_DualConvertedValueTab[0] <= 2000) {
						if (RecordMode()) {
							LCD_Clear(WHITE);
							break;
						}
					} else if (i == 1 && ADC_DualConvertedValueTab[2] >= 400
							&& ADC_DualConvertedValueTab[2] <= 2000) {
						if (OnlyPlayMode()) {
							LCD_Clear(WHITE);
							break;
						}
					} else if (i == 3 && ADC_DualConvertedValueTab[4] >= 400
							&& ADC_DualConvertedValueTab[4] <= 2000) {
						if (octave < 8)
							octave++;
						scale = &(graceful_scale_timer[octave * 12]);
					} else if (i == 3 && ADC_DualConvertedValueTab[5] >= 400
							&& ADC_DualConvertedValueTab[5] <= 2000) {
						if (octave > 0)
							octave--;
						scale = &(graceful_scale_timer[octave * 12]);

					} else
						semaphore = true;
				}
#ifdef DEBUG
				LCD_ShowNum(30, 70 + (i * 16), (i + 1), 2, BLACK, WHITE);
				LCD_ShowNum(160, 70 + (i * 16), (ADC_DualConvertedBorder[i]), 4,
						BLACK, WHITE);
				LCD_ShowNum(66, 70 + (i * 16), (ADC_DualConvertedValueTab[i]),
						4, BLACK, WHITE);

#endif
				if (semaphore) {
					Playscale(i);
					Delay(1);
#ifdef DEBUG
					LCD_ShowString(30, 280, "  ", WHITE, WHITE);
					LCD_ShowString(46, 280, "         ", WHITE, WHITE);
					LCD_ShowString(30, 280, key[i], RED, WHITE);
					LCD_ShowString(46, 280, "Pressed! ", RED, WHITE);
#endif
					getborder = semaphore;
					semaphore = false;
				}
				PlayOff();
			}
		}

	}
	return SUCCESS;
}

int main() {
	sysState = Boot();
	sysState &= operating_system();
	PlayOff();
	if (sysState) {
		return IDLE();
	}
}

