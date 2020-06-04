

#include "stm32f10x.h"
#include "hw_config.h"
#include "timer.h"

timer_service_function_type gbl_ar_timer_service[timerServiceFunctionMAX] = 
{
	{timer1ServiceFunction, NULL},
	{timer2ServiceFunction, NULL}
};
 
/* ------------------------------------------------------------------------------------------------- */
/* BSP Timer */
/* ------------------------------------------------------------------------------------------------- */

void register_timer_function(timer_register_function_type timer_fn_type, timer_register_function fn)
{
	gbl_ar_timer_service[timer_fn_type].run = fn;
}

void TIM2_IRQHandler(void)
{
	// Also cleared the wrong interrupt flag in the ISR
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	// TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // Clear the interrupt flag

	if( gbl_ar_timer_service[timer2ServiceFunction].run != NULL )
	{
		gbl_ar_timer_service[timer2ServiceFunction].run();
	}
}

void bsp_init_timer2(void/*isr_function timer2_isr*/)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;


	/* Enable the TIM2 global Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		

#ifdef NRF24L01_BPS_CHECK
	/* RF �׽�Ʈ������ �� ����� */
	/* 1msec ���� ���ͷ�Ʈ �߻� �ϵ��� ���� */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 12-1;	// ARR(Auto reload register)
	TIM_TimeBaseStructure.TIM_Prescaler = 6000-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
#else	
	/* 10msc ���� ���ͷ�Ʈ �߻� �ϵ��� ���� */
	// 10KHz = 1usec
	// 1Hz = 1sec, 10Hz = 100msec, 100Hz = 10msec, 1KHz = 1msec, 10KHz = 1usec, 100Khz = 0.1usec, 1MHz = 0.01usec

	// TIM2CLK = 72 MHz( APB1�� ���� 36MHz �ε� ���ָ� �ؼ� ����ϹǷ� 36*2 = 72MHz �� �ȴ�. )
	// �ð���  �⺻���� :S(��)-->nS.uS.mS.S.
	// 72000000/59999+1=1200 �� 1�ʿ� 1200�� Ŭ���� �߻��ϹǷ� 1199+1 ���� �ѹ� ���ͷ�Ʈ�� 
	// �߻��ϵ��� �����ϸ� 1�ʿ� �ѹ� ���ͷ�Ʈ�� �߻� �ϵ��� �Ѵ�.


	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 12-1;	// ARR(Auto reload register)
	TIM_TimeBaseStructure.TIM_Prescaler = 59999;	// 1MHz = 0.01usec
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
#endif




	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_Cmd(TIM2, ENABLE);	

	/* TIM IT enable */
	TIM_ITConfig(TIM2, TIM_IT_Update , ENABLE);	
}


u16 bsp_get_timer2_cnt(void)
{
	return TIM2->CNT;
}

void bsp_set_timer2_cnt( u16 cnt)
{
	TIM2->CNT = cnt;
}

