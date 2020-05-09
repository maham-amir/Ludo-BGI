#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>        // Provides exit
#include <ctype.h>         // Provides toupper
#define Max_Cols 1000
#define Max_Rows 800
#include"Ludo.h"
#include "Grid.h"

enum MyColor { Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6,	LightGay = 7, DarkGray = 8, 
	LitBlue = 9, LitGreen = 10, LitCyan = 11, LitRed = 12, 	LitMagenta = 13, Yellow = 14, White = 15 };

int main()
{
	
	initwindow(Max_Cols, Max_Rows);
	//
	//	/*int CA[] = { Magenta, LitMagenta, White, Red, LitRed, White, Green, LitGreen, White, Cyan, LitCyan, White };
	//	Grid Ludo(4, Max_Rows, Max_Cols, CA, 0);*/
	//light mode

	int CA[] = { LitBlue,Blue,  Black,  LitRed, Red,Black, LitGreen, Green, Black, Yellow, Brown, Black };
	Grid L(4, Max_Rows, Max_Cols, CA, 15);
	//dark mode

	L.PrintGrid();
	Ludo game;
	game.play();
	return 0;
}