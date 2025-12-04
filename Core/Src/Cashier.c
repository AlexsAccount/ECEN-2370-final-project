/*
 * Cashier.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#include "Cashier.h"


Cashier_HandleTypeDef cashier;


void cashier_Init()
{
    cashier_SetRandomBalance();
}

void cashier_SetBalance(uint32_t number)
{
    cashier.Balance = number;
}

void cashier_SetRandomBalance()
{
    uint32_t random_num;
    
    RNG_RandomNum(&random_num);
    random_num /= 100000000;
    random_num *= 100;
    
    cashier.Balance = random_num;   // balance is 4-digit decimal uint
}

uint32_t cashier_ReturnBalance()
{
    return cashier.Balance;
}