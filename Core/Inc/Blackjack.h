/*
 * Blackjack.h
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#ifndef INC_BLACKJACK_H_
#define INC_BLACKJACK_H_


#include "Cashier.h"
#include "RNG.h"
#include <stdbool.h>

#define PLAYER true
#define DEALER false


// enum value is for card identification purposes
// actual value is 10 for face cards
typedef enum BlackJack_Card_t
{
    ZERO,       // default value representing absence of card
    BUFFER,     // padding
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ACE,        // game value = 11
    JACK,       // game value = 10
    QUEEN,      // game value = 10
    KING        // game value = 10
} BlackJack_Card_t;

typedef struct BlackJack_Dealer_HandleTypeDef   // idk if i'm using "handle" term correctly here
{
    BlackJack_Card_t card1;
    BlackJack_Card_t card2;
    uint8_t hand_value;
} BlackJack_Dealer_HandleTypeDef;

typedef struct BlackJack_Player_HandleTypeDef
{
    BlackJack_Card_t card1;
    BlackJack_Card_t card2;
    BlackJack_Card_t card3;
    BlackJack_Card_t card4;
    BlackJack_Card_t card5;
    BlackJack_Card_t card6;
    uint8_t hand_value;
} BlackJack_Player_HandleTypeDef;



//                  BlackJack logic (simplified):
// player and dealer start with two random cards
//      - player hand is visible, dealer hand is hidden
//      - if player hand is ace + face card, automatic win
// option to "hit" or "stand"
//      - "hit" adds card to player hand
//      - "stand" reveals dealer hand and compares values.
// player wins if hand is higher than dealer's. loses if hand is higher than 21
//      - ace is 11 and face cards are 10. other card values unchanged


void blackJack_Init();          // set cards and hand_value to zero for player and dealer. meant to be called only once at app startup
void blackJack_NewRound();      // give random pair of cards to player and dealer
int blackJack_Hit();            // provide player with additional card and check for lose condition
bool blackJack_Stand();         // compare player and dealer hands

// Helpers
bool blackJack_Cheat();         // check for cheat condition and set player hand as ace + face card
bool blackJack_CompareCards();  // compare hand values
uint8_t blackJack_ReturnCardVal(BlackJack_Card_t card); // returns game value of card
uint8_t blackJack_CalcPlayerHandValue();    // sets and returns uint value of player hand
uint8_t blackJack_CalcDealerHandValue();    // sets and returns uint value of dealer hand
BlackJack_Card_t blackJack_RandCard();      // function to generate a random card


#endif /* INC_BLACKJACK_H_ */