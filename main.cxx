#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>        // Provides exit
#include <ctype.h>         // Provides toupper
#define Max_Cols 1000
#define Max_Rows 800
#include"Ludo.h"
#include "Grid.h"



int main()
{
	Ludo game;
	game.play();
	return 0;
}