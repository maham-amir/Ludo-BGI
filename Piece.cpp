#include "Piece.h"

Piece::Piece() :hasKilled(false), hasHomed(false), isOut(false), isSafe(true), position(0)
{}

void Piece::bringOut()
{
	isOut = true;
}

Piece::Piece(int p, COLOUR c) :position(p), hasKilled(0), hasHomed(0), isOut(0), isSafe(1), color(c)
{

}



