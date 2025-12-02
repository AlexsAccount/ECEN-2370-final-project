/*
 * RNG.h
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#ifndef INC_RNG_H_
#define INC_RNG_H_


#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_msp.c"

void RNG_Init();
uint32_t RNG_RandomNum(uint32_t *number); // 32-bit generated number


#endif /* INC_RNG_H_ */