#include "Player.h"
#include"Ludo.h"
Player::Player()
{
}

Player::Player(COLOUR c, Position sp, Ludo l):color(c), startPos(sp)
{
	for (int i = 0; i < 4; i++)
	{
		Pieces.push_back(&Piece(sp.boxnum, c));
	}
}

void Player::removePiece(int i)
{
	Pieces.erase(Pieces.begin() + i);
}