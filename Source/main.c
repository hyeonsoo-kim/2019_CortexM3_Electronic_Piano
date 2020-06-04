
#include "api.h"
#define MAXIMUM 256
uint16_t press;
ErrorStatus Keyboard_On(void);
ErrorStatus operating_system(void);
void PlayOn(void);
_uint ADC_DualConvertedValueTab[12] = {0,};
_uint ADC_DualConvertedBorder[12] = {0,};

bool getborder = false;

void getcalibration(){
	if(!getborder){
		for (_uchar i = 0; i< 12; i++){
				 ADC_DualConvertedBorder[i] = ADC_DualConvertedValueTab[i];
			}
		getborder = true;
		}
}

_uint current_time = 0;
_uint running_time = 0;

void time_rewind() {
	current_time = 0;
}

typedef struct _note {
	_uint start_time;
	_uint end_time;
	_uchar scale_idx;
} Note;

Note memnotes[MAXIMUM];

_uint totaltime = 0U;

bool is_recoding = false;

typedef struct
{
   _nv_ushort prescaler;
   _nv_ushort period;
} timer_frq;


timer_frq scale[12] = {
	 {  6,45867}
	,{  4,64939}
	,{  4,61294}
	,{  4,57854}
	,{  4,54607}
	,{  4,51542}
	,{ 13,14969}
	,{  3,61225}
	,{ 17,10198}
	,{  4,40909}
	,{  3,51484}
	,{ 11,13253}
};

typedef TIM_TimeBaseInitTypeDef TIMERinitdata;

void Timer_Configure(void){
	TIMERinitdata _data;
	_data.TIM_ClockDivision = TIM_CKD_DIV1;
	_data.TIM_CounterMode = TIM_CounterMode_Up;
	_data.TIM_Period = 1000;
	_data.TIM_Prescaler = 7200;
	_data.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&_data);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM2,ENABLE);
}

void TIM2_IRQHandler(void) {
	if (is_recoding){
		totaltime++;
		}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
}



ErrorStatus Boot() {
	ErrorStatus result = ERROR;
	result = SysBoot();
	result &= lcdon();
	result &= RCCSwitch(200,ENABLE);
	result &= RCCSwitch(201,ENABLE);
	result &= RCCSwitch(202,ENABLE);
	result &= RCCSwitch(203,ENABLE);
	result &= ADC_PowerON(1);
	result &= Keyboard_On();

	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	//RCC_ADCCLKConfig(RCC_PCLK2_Div6); //clock for ADC (max 14MHz, 72/6=12MHz)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //enable ADC clock

	// DMA1 channel1 configuration ----------------------------------------------
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_DualConvertedValueTab;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = 12;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word; // 32bit
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word; // 32bit
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	// Enable DMA1 Channel1

	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);
	DMA_Cmd(DMA1_Channel1, ENABLE); //Enable the DMA1 - Channel1

	result &= NVIC_Register(DMA1_Channel1_IRQn,ENABLE,0,0);

	if (result) {
		LCD_ShowString(50,50,"Boot Completed!", WHITE, BLACK);
#ifdef DEBUG
		LCD_ShowString(50,66,"IN Key DEBUG MODE!", YELLOW, BLACK);
#endif
	}
	else LCD_ShowString(50,50,"Error! Please Check!", WHITE, BLACK);
	return result;
}

extern ADCInfo ADC_1;

ErrorStatus Keyboard_On(){
	ErrorStatus result = ERROR;
	result = ADC_Initialize(&ADC_1);
	if (result) {
		result &= ADC_Multiple_Regcfg(&ADC_1);
		//result &= ADC_IntrruptSwitch(ADC1, ADC_IT_EOC, ENABLE);
		result &= ADC_ON(ADC1);
		result &= ADC_DataCalibration(ADC1);
		ADC_DMACmd(ADC1, ENABLE);
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	}
	return result;
}

void PlayOn(){
	TIM_Cmd(TIM4, ENABLE);
}

void PlayOff(){
	TIM_Cmd(TIM4, DISABLE);
}

/*
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
*/

ErrorStatus operating_system( ){
	GPIO_Initialize(GPIOB, 8, GPIO_Speed_50MHz, GPIO_Mode_AF_PP);
	RCCSwitch(102,ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure ;

	for (int i = 0; i< 12 ; i++){

	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseStructure.TIM_Period = scale[i].period-1;
	TIM_TimeBaseStructure.TIM_Prescaler = scale[i].prescaler-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	TIM_OCInitTypeDef OC;
	OC.TIM_OCMode = TIM_OCMode_PWM1;
	OC.TIM_OCPolarity = TIM_OCPolarity_High;
	OC.TIM_OutputState = TIM_OutputState_Enable;
	OC.TIM_Pulse = 1000;

	TIM_OC3Init(TIM4, &OC);

	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM4->EGR = TIM_PSCReloadMode_Immediate;
	TIM_Cmd(TIM4,ENABLE);
	Delay(1);
	}
	PlayOff();
	return SUCCESS;
}

bool semaphore = false;

void Playscale(_uchar idx){

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure ;

	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseStructure.TIM_Period = scale[idx].period-1;
	TIM_TimeBaseStructure.TIM_Prescaler = scale[idx].prescaler-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	PlayOn();
}

ErrorStatus RecordMode(){
	LCD_Clear(WHITE);
	return SUCCESS;
}

ErrorStatus OnlyPlayMode(){
	LCD_Clear(WHITE);
	return SUCCESS;
}

ErrorStatus IDLE(){
	ShapedButton Rec, Rec2;
	LCD_Clear(WHITE);
	LCD_ShowSizedString(40,10,"YALLACHA PIANO",18,BLACK,WHITE);
	createRectangleButton(&Rec,"Record",50,50,70,100);
	createRectangleButton(&Rec2,"Play",50,130,70,100);
	LED_Init_ALL();
	LED_Power_On();
#ifndef DEBUG
	showRectangleButton(&Rec);
	showRectangleButton(&Rec2);
#else
	LCD_ShowString(40,30,"KeyBoard Debug Mode",BLACK,WHITE);
	LCD_DrawLine(25,48,200,48);
	LCD_ShowString(30,50,"Num Press Calibration",BLACK,WHITE);
	LCD_DrawLine(25,68,200,68);
	LCD_DrawLine(25,262,200,262);
	char* key[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
#endif
		while(1) {
#ifndef DEBUG
			Touch_Input();
					if (RetangleBtnOnClick(&Rec,&conv_ptr)){
						if (RecordMode()){
							LCD_Clear(WHITE);
							showRectangleButton(&Rec);
							showRectangleButton(&Rec2);
							continue;
						}
					}
					else if (RetangleBtnOnClick(&Rec2,&conv_ptr)){
						if (OnlyPlayMode()){
							LCD_Clear(WHITE);
							showRectangleButton(&Rec);
							showRectangleButton(&Rec2);
							continue;
						}
					}
#endif
			if (!interrupt_semaphore ){
			for (_uchar i = 0; i< 12; i++){
				ADC_DualConvertedValueTab[i]-=ADC_DualConvertedBorder[i];
				if ((_sint)ADC_DualConvertedValueTab[i] < 0) ADC_DualConvertedValueTab[i] = 0;
				else if ( ADC_DualConvertedValueTab[i] >= 400 && ADC_DualConvertedValueTab[i] <=2000 ){
					semaphore = true;
				}
#ifdef DEBUG
				LCD_ShowNum(30,70+(i*16),(i+1),2, BLACK, WHITE);
				LCD_ShowNum(160,70+(i*16),(ADC_DualConvertedBorder[i]),4, BLACK, WHITE);
				LCD_ShowNum(66,70+(i*16),(ADC_DualConvertedValueTab[i]),4, BLACK, WHITE);

#endif
				if (semaphore) {
					Playscale(i);
					Delay(1);
#ifdef DEBUG
					LCD_ShowString(30,280, "  ", WHITE, WHITE);
					LCD_ShowString(46,280, "         ", WHITE,WHITE);
					LCD_ShowString(30,280, key[i], RED,WHITE);
					LCD_ShowString(46,280, "Pressed! ", RED,WHITE);
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


