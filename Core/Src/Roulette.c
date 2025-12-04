/*
 * Roulette.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#include "Roulette.h"

Roulette_Bet_t bet;
Roulette_Num_t dealer;


void roulette_Init()
{
    // do i even need this?...
    
}

void roulette_Generate()
{
    uint32_t temp_val;
    RNG_RandomNum(temp_val);
    temp_val %= 17;

    dealer = (Roulette_Num_t) temp_val;
}

void roulette_Payout()
{
    uint32_t temp_bal;
    temp_bal = cashier_ReturnBalance();
    
    if (roulette_Compare())
    {
        if (bet.choice == COLOR)
        {
            temp_bal += 50;
        }
        else if (bet.choice == NUM_COLOR)
        {
            temp_bal += 200;
        }
    }
    else { temp_bal -= 100; }

    cashier_SetBalance(temp_bal);
}

// 0=lose, 1=win
bool roulette_Compare()
{
    uint8_t num_val = ((uint8_t) dealer);
    uint8_t even_odd = num_val % 2;  // 0=even=black, 1=odd=red

    if (bet.choice == COLOR)
    {
        if (bet.color == BLACK)
        {
            if (even_odd == BLACK) { return 1; }
            else { return 0; }
        }
        else if (bet.color == RED)
        {
            if (even_odd == RED) { return 1; }
            else { return 0; }
        }
    }
    else if ((bet.choice == NUM_COLOR) && (bet.number == num_val))
    {
        return 1;
    }
    else { return 0; }
}


void roulette_Cheat()
{
    if (bet.choice == NUM_COLOR)
    {
        dealer = (Roulette_Num_t) bet.number;
    }
    else if (bet.choice == COLOR)
    {
        dealer = (Roulette_Num_t) ((int)bet.color + 2);
    }
}

