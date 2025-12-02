/*
 * Cashier.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#include "Cashier.h"

extern RNG_HandleTypeDef hrng;

void cashier_Init(Cashier_HandleTypeDef *cashier)
{
    cashier->Balance = 0;
}

void cashier_SetBalance(Cashier_HandleTypeDef *cashier, uint32_t number)
{
    cashier->Balance = number;
}

void cashier_RandomBalance(Cashier_HandleTypeDef *cashier)
{
    uint32_t random_num = RNG_RandomNum(&random_num);
    cashier->Balance = random_num;
}

uint32_t cashier_ReturnBalance(Cashier_HandleTypeDef *cashier)
{
    return cashier->Balance;
}