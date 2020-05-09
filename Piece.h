#include"Position.h"
enum COLOUR { red, yellow, green, blue, orange, purple };
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
	virtual void draw(); //used to print at position
	virtual void undraw(); // undraws at position
};

