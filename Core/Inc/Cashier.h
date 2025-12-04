/*
 * Cashier.h
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#ifndef INC_CASHIER_H_
#define INC_CASHIER_H_


#include <stdint.h>
#include "RNG.h"
// "Deals with the $$$"

typedef struct Cashier_HandleTypeDef
{
    uint32_t Balance;
} Cashier_HandleTypeDef;


void cashier_Init();
void cashier_SetBalance(uint32_t number);
void cashier_SetRandomBalance();
uint32_t cashier_ReturnBalance();


#endif /* INC_CASHIER_H_ */