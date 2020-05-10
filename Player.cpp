#include "Player.h"
#include"Ludo.h"
Player::Player()
{
}

Player::Player(COLOUR c, Position sp):color(c), startPos(sp)
{
	for (int i = 0; i < 4; i++)
	{
		Piece* p = new Piece(sp.boxnum, c);
		Pieces.push_back(p);
	}
}

void Player::removePiece(int i)
{
	Pieces.erase(Pieces.begin() + i);
}