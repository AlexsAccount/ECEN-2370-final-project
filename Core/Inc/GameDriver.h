/*
 * GameDriver.h
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#ifndef INC_GAMEDRIVER_H_
#define INC_GAMEDRIVER_H_


#include "Blackjack.h"
#include "Roulette.h"
#include "Cashier.h"
#include "LCD_Driver.h"

// "Would generate your screens and control basic display logic"


void game_Init();

void game_LoadMainScreen();
void game_LoadRouletteScreen();
void game_LoadBlackJackScreen();
void game_BalanceCheck();
void game_CheatEnable();    // 1sec, 2sec, then quick press (rise+fall trigger)


#endif /* INC_GAMEDRIVER_H_ */