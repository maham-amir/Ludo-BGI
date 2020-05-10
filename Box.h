//#include"Piece.h"
#include<iostream>
#include<vector>
using namespace std;

#pragma once
#include"Position.h"
class Piece;
class Box
{
	Position position;
	vector <Piece*> PiecesHere;
	bool isSafeSpot;

public:
	Box(int,bool);
	friend class Ludo;
};

