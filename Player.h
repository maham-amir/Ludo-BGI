#include "Piece.h"
#include "Position.h"
#include<vector>
#include<iostream>
using namespace std;



#pragma once
class Player
{
	vector<Piece*>Pieces;
	COLOUR color;
	Position startPos;

public:
	friend class Ludo;
	Player();
	Player(COLOUR, Position);
	void removePiece(int);

};

