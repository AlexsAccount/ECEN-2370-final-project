/*
 * RNG.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#include "RNG.h"

RNG_HandleTypeDef hrng = {0};

void RNG_Init()
{
	hrng.Instance = RNG;
    
	__HAL_RCC_RNG_CLK_ENABLE();
    HAL_RNG_Init(&hrng);
}

uint32_t RNG_RandomNum(uint32_t *number)
{
    HAL_RNG_GenerateRandomNumber(&hrng, &number);
    return;
}