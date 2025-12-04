/*
 * Roulette.h
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#ifndef INC_ROULETTE_H_
#define INC_ROULETTE_H_


#include <stdbool.h>
#include "RNG.h"
#include "Cashier.h"


#define COLOR 0
#define NUM_COLOR 1
#define BLACK 0
#define RED 1


typedef enum Roulette_Num_t
{
    OUGHT,
    ONE_R,
    TWO_B,
    THREE_R,
    FOUR_B,
    FIVE_R,
    SIX_B,
    SEVEN_R,
    EIGHT_B,
    NINE_R,
    TEN_B,
    ELEVEN_R,
    TWELVE_B,
    THIRTEEN_R,
    FOURTEEN_B,
    FIFTEEN_R,
    DOUBLE_OUGHT
} Roulette_Num_t;

typedef struct Roulette_Bet_t
{
    bool choice;    // 0=color, 1=num+color
    bool color;     // 0=black, 1=red
    uint8_t number;
} Roulette_Bet_t;



//                  Roulette logic (simplified):
// player picks color or number+color.
//      - numbers: 0, 00, 1-15
//      - colors: red, black
// random number and color is generated and compared
//      - color win $50
//      - number+color win $200 (also with 0 and 00)
//      - no match lose $100

void roulette_Init();
void roulette_Generate();
void roulette_Payout();
bool roulette_Compare();

void roulette_Cheat();


#endif /* INC_ROULETTE_H_ */