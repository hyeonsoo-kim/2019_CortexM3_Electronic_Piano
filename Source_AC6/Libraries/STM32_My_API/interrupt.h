#ifndef INTERRUPT_H_INCLUDED
#define INTERRUPT_H_INCLUDED


#include "system_foundation.h"
#include "misc.h"
#include "stm32f10x_exti.h"

#ifdef GCC
#include "misc.c"
#include "stm32f10x_exti.c"
#endif

/**
 * EXTI Configuration
 */
typedef EXTIMode_TypeDef EXTIMode;
typedef EXTITrigger_TypeDef EXTITrigger;

extern void getcalibration();

ErrorStatus EXTI_Register(_nv_uint line, EXTIMode mode, EXTITrigger trig, FunctionalState cmd){
	ErrorStatus result = ERROR;
	EXTI_InitTypeDef data;
	data.EXTI_Line = line;
	data.EXTI_LineCmd = cmd;
	data.EXTI_Trigger = trig;
	data.EXTI_Mode = mode;
	EXTI_Init(&data);
	result = SUCCESS;
	return result;
}

ErrorStatus EXTI_Delete(_nv_uint line){
	ErrorStatus result = ERROR;
	EXTI_InitTypeDef data;
	EXTI_StructInit(&data);
	data.EXTI_Line = line;
	EXTI_Init(&data);
	result = SUCCESS;
	return result;
}

ErrorStatus EXTI_Clear(void) {
	EXTI_DeInit();
	return SUCCESS;
}

typedef NVIC_InitTypeDef NVICInitdata;


ErrorStatus NVIC_PGroup_Setting(_c_nv_uint groupname) {
	ErrorStatus result = ERROR;
	bool valid = IS_NVIC_PRIORITY_GROUP(groupname);
	if (valid) {
		NVIC_PriorityGroupConfig(groupname);
		result = SUCCESS;
	}
	return result;
}


bool irq_is_valid(_c_nv_sint code){
	  bool result = (code == -14);
	  result |= (code == -14);
	  result |= (code == -12);
	  result |= (code == -11);
	  result |= (code == -10);
	  result |= (code == -5);
	  result |= (code == -4);
	  result |= (code == -2);
	  result |= (code == -1);
	  result |= ( (code >=0) && (code <=68) );
	  return result;

  }

ErrorStatus NVIC_Register(const IRQn_Type irq, const FunctionalState cmd,
						  _c_nv_uchar pre_priority, _c_nv_uchar sub_priority  ) {
	NVICInitdata _data;
	ErrorStatus result = ERROR;
	bool valid = irq_is_valid(irq);
	valid &= IS_FUNCTIONAL_STATE(cmd);
	valid &= IS_NVIC_PREEMPTION_PRIORITY(pre_priority) && IS_NVIC_SUB_PRIORITY(sub_priority);
	if(valid) {
		NVIC_EnableIRQ(irq);
		_data.NVIC_IRQChannel = irq;
		_data.NVIC_IRQChannelCmd = cmd;
		_data.NVIC_IRQChannelPreemptionPriority = pre_priority;
		_data.NVIC_IRQChannelSubPriority = sub_priority;
		NVIC_Init(&_data);
		result = SUCCESS;
	}
	return result;
}

bool interrupt_semaphore = false;

void DMA1_Channel1_IRQHandler(void)
{
 //Test on DMA1 Channel1 Transfer Complete interrupt
 if(DMA_GetITStatus(DMA1_IT_TC1))
 {
   interrupt_semaphore = true;
   getcalibration();
   DMA_ClearITPendingBit(DMA1_IT_TC1 | DMA1_IT_GL1);
   interrupt_semaphore = false;
   }
}




#endif
