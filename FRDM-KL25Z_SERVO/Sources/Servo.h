/*
 * Servo.h
 *
 *  Created on: 08/04/2017
 *      Author: milton
 */

#ifndef SOURCES_SERVO_H_
#define SOURCES_SERVO_H_

typedef struct
{
  uint16_t min_uCnv;
  uint16_t max_uCnv;
  uint16_t uMod;
  uint16_t stepVal;
  tpm_pwm_param_t *param;
  uint32_t instance;
  uint8_t channel;
  uint32_t freq;
} SERVO_HANDLER_T, * SERVO_HANDLER_PTR;

/**
 * @brief	Init the servo
 * @param[servoPtr] Pointer to the struct servo handler
 * @param[minPulseWidth_us] minimal duty cycle
 * @param[maxPulseWidth_us] maximal duty cycle
 * @return	void
 */
void SERVO_Init(SERVO_HANDLER_PTR servoPtr, uint16_t minPulseWidth_us, uint16_t maxPulseWidth_us);

/**
 * @brief	Set the position of the servo
 * @param[servoPtr] Pointer to the struct servo handler
 * @param[angle] 0 to 180 degree
 * @return	tpm_status_t
 */
tpm_status_t SERVO_Write(SERVO_HANDLER_PTR servoPtr, uint8_t angle);


#endif /* SOURCES_SERVO_H_ */
