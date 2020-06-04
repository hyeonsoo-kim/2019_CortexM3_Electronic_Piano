#ifndef _DMA_H
#define _DMA_H

#include "system_foundation.h"

typedef DMA_InitTypeDef  DMAInitdata;
typedef DMA_Channel_TypeDef* DMAChannel;
ErrorStatus DMA_Initialize( DMAChannel _DMAy_Channelx, uint32_t _DMA_PeripheralBaseAddr,
		uint32_t _DMA_MemoryBaseAddr,uint32_t _DMA_DIR,uint32_t _DMA_BufferSize,
		uint32_t _DMA_PeripheralInc, uint32_t _DMA_MemoryInc,uint32_t _DMA_PeripheralDataSize,
		uint32_t _DMA_MemoryDataSize,uint32_t _DMA_Mode, uint32_t _DMA_Priority,
		uint32_t _DMA_M2M
		){
	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(_DMAy_Channelx);
	DMA_InitStructure.DMA_PeripheralBaseAddr = _DMA_PeripheralBaseAddr;
	DMA_InitStructure.DMA_MemoryBaseAddr = _DMA_MemoryBaseAddr;
	DMA_InitStructure.DMA_DIR = _DMA_DIR;
	DMA_InitStructure.DMA_BufferSize = _DMA_BufferSize;
	DMA_InitStructure.DMA_PeripheralInc = _DMA_PeripheralInc;
	DMA_InitStructure.DMA_MemoryInc = _DMA_MemoryInc;
	DMA_InitStructure.DMA_PeripheralDataSize = _DMA_PeripheralDataSize;
	DMA_InitStructure.DMA_MemoryDataSize = _DMA_MemoryDataSize;
	DMA_InitStructure.DMA_Mode = _DMA_Mode;
	DMA_InitStructure.DMA_Priority = _DMA_Priority;
	DMA_InitStructure.DMA_M2M =_DMA_M2M;
	DMA_Init(_DMAy_Channelx, &DMA_InitStructure);
	return SUCCESS;
}


#endif
