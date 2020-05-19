#include<iostream>
#include<vector>
#include "graphics.h"
#include <math.h>
#include <stdlib.h>        // Provides exit
#include <ctype.h>         // Provides toupper
#include "Position.h"
using namespace std;
class Piece;
class Player;
class Box;
#include"Box.h"
#include"Piece.h"
#include"Player.h"
#include "Grid.h"
#pragma once
class Ludo
{
	vector<Player*>Players;
	int Plyturn;
	int Ver;
	vector <int> DiceRolls;
	vector<Player*>PlayersWon;
	vector<Position>Stops;
	vector<Box*>Boxes;
	Position S, E;
	Piece* currPiece;
	Grid grid;

	vector<int>DiceSumIndexes;
	void CalcValidSumindexes(int Sum);
	int SumOfDiceBinaryIndexs(bool* bptr, int B_size);
public:
	Ludo();
	int getVersion();
	void setVersion(int);
	void kill();
	void ChangeTurn();
	void PrintTurnMsg();
	int Rolldice();
	void SelectPiece();
	bool IsValidSelection();
	bool IsValidDestination(int);
	bool CanMov(Piece*, int B_E);
	bool IsVacantSpot(Position);
	void RemovePlayer();
	void move();
	Piece* getSelectedPiece(int);
	void play();
	void storeDiceRoll(int);
	bool iskill(Box*);
	void init(int);
	bool isDiceClicked(int, int);
	bool IsWin(int);
	void Update(Piece*);
	void AddWinnerToList(Player*);
	void getAllDiceRolls();
	void drawPiece(int);
	void undrawPiece(int);
};
