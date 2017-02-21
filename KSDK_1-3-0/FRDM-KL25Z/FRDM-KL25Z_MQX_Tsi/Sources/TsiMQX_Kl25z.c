/*
 * TsiMQX_Kl25z.c
 *
 *  Created on: 16/02/2017
 *      Author: milton
 */


#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"
#include "TsiMQX_Kl25z.h"
#include <stdint.h>
#include <stdio.h>

/* ----------------- PRIVATE FUCTIONS  ----------------------------  */

uint32_t readElectrodes(TSI_STATUS_PTR tsiH, uint8_t samples){
	uint8_t i, j;
	uint32_t sum, avg = 0;
	uint32_t result;
	uint16_t measureResult[QTD_ELECTRODES];
	for (i = 0; i < samples; i++) {
		for (j = 0; j < QTD_ELECTRODES; j++) {
			result = TSI_DRV_GetCounter(tsi1_IDX, tsiH->tsiChannel[i],
					&measureResult[j]);
			if (result != kStatus_TSI_Success) {
				printf("\r\nThe read of TSI channel %d failed.",
						tsiH->tsiChannel[i]);
				return FALSE;
			}
			// Calculates sum of average values.
			sum += measureResult[j];
		}
	}
	// Calculates average value afer samples measurement.
	avg = sum/(samples * QTD_ELECTRODES);
	return avg;
}
/* -------------------------------------------------------------------*/



/* ----------------- PUBLIC FUCTIONS  ----------------------------  */


bool TsiMQXKl25z_Init(TSI_STATUS_PTR tsiH){
	uint8_t i;
	uint32_t result;
	tsiH->tsiChannel[0] = CHANNEL_9;
	tsiH->tsiChannel[1] = CHANNEL_10;

	// Enable electrodes for normal mode
	for (i = 0; i < QTD_ELECTRODES; i++) {
		result = TSI_DRV_EnableElectrode(tsi1_IDX, tsiH->tsiChannel[i], true);
		if (result != kStatus_TSI_Success) {
			printf("\r\nThe initialization of TSI channel %d failed \r\n",
					tsiH->tsiChannel[i]);
			return FALSE;
		}
	}

	// Measures average value in untouched mode.
	tsiH->avgUntouch = readElectrodes(tsiH, SAMPLES_FOR_CALIBRATE);
	if(tsiH->avgUntouch == 0){
		return FALSE;
	}
	return TRUE;
}


void TsiMQXKl25z_GetElectrodesStatus(TSI_STATUS_PTR tsiH){
	if(tsiH->avgUntouch == 0) return;
	tsiH->avgMeasure = readElectrodes(tsiH, ONE_READ);

	if(tsiH->avgMeasure > tsiH->avgUntouch + THERESHOLD_FOR_TOUCH){
		printf("new measure %d\r\n",(int)tsiH->avgMeasure);
	}
}


