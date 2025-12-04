/*
 * Blackjack.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#include "Blackjack.h"


BlackJack_Dealer_HandleTypeDef dealer;
BlackJack_Player_HandleTypeDef player;


void blackJack_Init()
{
    dealer.card1 = ZERO;
    dealer.card2 = ZERO;
    dealer.hand_value = 0;

    player.card1 = ZERO;
    player.card2 = ZERO;
    player.card3 = ZERO;
    player.card4 = ZERO;
    player.card5 = ZERO;
    player.card6 = ZERO;
    player.hand_value = 0;
}

void blackJack_NewRound()
{
    dealer.card1 = blackJack_RandCard();
    dealer.card2 = blackJack_RandCard();
    dealer.hand_value = blackJack_CalcDealerHandValue();

    player.card1 = blackJack_RandCard();
    player.card2 = blackJack_RandCard();
    player.card3 = ZERO;
    player.card4 = ZERO;
    player.card5 = ZERO;
    player.card6 = ZERO;
    player.hand_value = blackJack_CalcPlayerHandValue();
}

// -1 = error occured
//  0 = player already has max of 6 cards
//  1 = new hand value exceeds 21 (lose)
//  2 = new hand value is at or below 21
int blackJack_Hit()
{
    // check if card slots full
    if (player.card6 != 0) { return 0; }
    
    // fill lowest number open card slot
    if (!player.card3) { player.card3 = blackJack_RandCard(); }
    else if (!player.card4) { player.card4 = blackJack_RandCard(); }
    else if (!player.card5) { player.card5 = blackJack_RandCard(); }
    else if (!player.card6) { player.card6 = blackJack_RandCard(); }

    blackJack_CalcPlayerHandValue();
    if (player.hand_value > 21) { return 1; }
    else if (player.hand_value <= 21) { return 2; }

    return -1;
}

// returns winner (player=1 or dealer=0)
bool blackJack_Stand()
{
    return blackJack_CompareCards();
}



// Helpers

bool blackJack_Cheat()
{
    player.card1 = ACE;
    player.card2 = KING;
    player.hand_value = 21;
}

// returns winner (player=1 or dealer=0)
bool blackJack_CompareCards()
{
    if (player.hand_value < dealer.hand_value) { return DEALER; }
    else { return PLAYER; }
}

// assumes that card enum argument is valid and not BUFFER. (is_valid && !BUFFER)
uint8_t blackJack_ReturnCardVal(BlackJack_Card_t card)
{
    int temp_val;

    switch (card)
    {
    case JACK:
        temp_val = 10;
        break;
    case QUEEN:
        temp_val = 10;
        break;
    case KING:
        temp_val = 10;
        break;
    
    default:
        temp_val = card;
        break;
    }

    return ( (uint8_t) temp_val );
}

uint8_t blackJack_CalcPlayerHandValue()
{
    uint8_t temp_card1 = blackJack_ReturnCardVal(player.card1);
    uint8_t temp_card2 = blackJack_ReturnCardVal(player.card2);
    uint8_t temp_card3 = blackJack_ReturnCardVal(player.card3);
    uint8_t temp_card4 = blackJack_ReturnCardVal(player.card4);
    uint8_t temp_card5 = blackJack_ReturnCardVal(player.card5);
    uint8_t temp_card6 = blackJack_ReturnCardVal(player.card6);

    uint8_t temp_val = (temp_card1
                      + temp_card2
                      + temp_card3
                      + temp_card4
                      + temp_card5
                      + temp_card6);

    player.hand_value = temp_val;

    return temp_val;
}

uint8_t blackJack_CalcDealerHandValue()
{
    uint8_t temp_card1 = blackJack_ReturnCardVal(dealer.card1);
    uint8_t temp_card2 = blackJack_ReturnCardVal(dealer.card2);

    uint8_t temp_val = (temp_card1
                      + temp_card2);

    dealer.hand_value = temp_val;

    return temp_val;
}

BlackJack_Card_t blackJack_RandCard()
{
    uint32_t temp_num;
    
    while (temp_num < 2 || temp_num > 14)
    {
        RNG_RandomNum(&temp_num);
        temp_num %= 15;
    }

    return ( (BlackJack_Card_t) temp_num );
}
