#include"Position.h"
static enum COLOUR { red, green,brown, blue, orange, purple };
#pragma once
class Piece
{
protected:
	Position position; //contains box num
	bool hasKilled;
	bool hasHomed;
	bool isOut;
	bool isSafe;

public:
	COLOUR color;
	friend class Ludo;
	Piece();
	Piece(int, COLOUR);
	void bringOut();
	void draw(); //used to print at position
	void undraw(); // undraws at position
};

