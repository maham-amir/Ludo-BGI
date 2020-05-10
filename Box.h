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

public:
	Box(int);
	friend class Ludo;
};

