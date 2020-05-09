#include<iostream>
#include<vector>
#include "Position.h"
using namespace std;
class Piece;
class Player;
class Box;
#include"Box.h"
#include"Piece.h"
#include"Player.h"
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
public:
	int getVersion();
  void setVersion(int);
	void ChangeTurn();
	void PrintTurnMsg();
	void Rolldice();
	void SelectPiece();
	bool IsValidSelection();
	bool IsValidDestination();
	bool IsVacantSpot();
	void RemovePlayer();
  	//code by BSCS19065

	Piece* getSelectedPiece(int);
	void play();

	bool iskill();
	void init(int);
	void Update();
	void Highlight();
	void UnHighlight();
	void DisplayBoard();
	void AddWinnerToList(Player*);
	// end code by BSCS19065
};
