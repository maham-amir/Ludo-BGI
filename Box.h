#include"Piece.h"
#include "Position.h"
#include<iostream>
using namespace std;
//
//class Piece;
//class Position;

#pragma once
class Box
{
	Position position;
	vector<Piece*> Pieces;

public:
	Box();
	friend class Ludo;
};

