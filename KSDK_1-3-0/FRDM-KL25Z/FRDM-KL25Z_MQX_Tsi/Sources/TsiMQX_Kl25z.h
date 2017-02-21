/*
 * TsiMQX_Kl25z.h
 *
 *  Created on: 16/02/2017
 *      Author: milton
 */

#ifndef SOURCES_TSIMQX_KL25Z_H_
#define SOURCES_TSIMQX_KL25Z_H_

#define QTD_ELECTRODES 	2
#define CHANNEL_9 		9
#define CHANNEL_10 		10
#define SAMPLES_FOR_CALIBRATE 		100u
#define ONE_READ 1
#define THERESHOLD_FOR_TOUCH 10

typedef struct{
	uint8_t tsiChannel[QTD_ELECTRODES];
	uint32_t avgMeasure;
	uint32_t avgUntouch;
}TSI_STATUS_T, *TSI_STATUS_PTR;


bool TsiMQXKl25z_Init(TSI_STATUS_PTR tsiH);


void TsiMQXKl25z_GetElectrodesStatus(TSI_STATUS_PTR tsiH);

#endif /* SOURCES_TSIMQX_KL25Z_H_ */
