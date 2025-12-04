/*
 * GameDriver.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Alex
 */

#include "GameDriver.h"


void game_Init()
{
    
    LCD_Clear(LCD_COLOR_WHITE);
    LCD_SetFont(&Font16x24);
    LCD_SetTextColor(LCD_COLOR_BLACK);
    
    LCD_DisplayChar( 95,140,'W');
	LCD_DisplayChar(105,140,'e');
	LCD_DisplayChar(115,140,'l');
	LCD_DisplayChar(120,140,'c');
	LCD_DisplayChar(130,140,'o');
	LCD_DisplayChar(140,140,'m');
	LCD_DisplayChar(150,140,'e');
	LCD_DisplayChar(160,140,'!');
    
	LCD_DisplayChar(115,160,':');
	LCD_DisplayChar(120,160,'D');
	
    RNG_Init();
    cashier_Init();
    blackJack_Init();
    // roulette init?



    HAL_Delay(2500);
    game_LoadMainScreen();

}


void game_LoadMainScreen()
{
    LCD_Clear(LCD_COLOR_DARKGREEN);

    
	LCD_Draw_Vertical_Line(10,10,250,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(120,10,250,LCD_COLOR_BLACK);

	LCD_DisplayChar(100,140,'t');
	LCD_DisplayChar(110,140,'e');   // off-center?
	LCD_DisplayChar(120,140,'s');
	LCD_DisplayChar(130,140,'t');

    LCD_DisplayChar(100,160,'t');
	LCD_DisplayChar(116,160,'e');
	LCD_DisplayChar(132,160,'s');
	LCD_DisplayChar(148,160,'t');

    LCD_DisplayInt(10, 310, cashier_ReturnBalance());   // characters start pos on top or bottom left??

    while (1)
    {
        HAL_Delay(1000);
    }
}

void game_LoadRouletteScreen()
{
    LCD_Clear(LCD_COLOR_DARKGREEN);
    
}

void game_LoadBlackJackScreen()
{
    LCD_Clear(LCD_COLOR_DARKGREEN);

}

void game_BalanceCheck()
{

}

void game_CheatEnable()
{

}




extern FONT_t *LCD_Currentfonts;

void LCD_DisplayInt(uint16_t Xpos, uint16_t Ypos, int value)
{
    char temp_str[12];  
    sprintf(temp_str, "%d", value);

    uint16_t Xcursor = Xpos;

    for (int i = 0; temp_str[i] != '\0'; i++)
    {
        LCD_DisplayChar(Xcursor, Ypos, temp_str[i]);
        Xcursor += LCD_Currentfonts->Width;
    }
}
