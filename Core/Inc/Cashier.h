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


void cashier_Init(Cashier_HandleTypeDef *cashier);
void cashier_SetBalance(Cashier_HandleTypeDef *cashier, uint32_t number);
void cashier_RandomBalance(Cashier_HandleTypeDef *cashier);
uint32_t cashier_ReturnBalance(Cashier_HandleTypeDef *cashier);


#endif /* INC_CASHIER_H_ */