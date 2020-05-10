#include "Ludo.h"
#include "Piece.h"
#include "Player.h"
#include"Box.h"
#include"Grid.h"
#include<time.h>

enum MyColor {
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGay = 7, DarkGray = 8,
	LitBlue = 9, LitGreen = 10, LitCyan = 11, LitRed = 12, LitMagenta = 13, Yellow = 14, White = 15
};
void Ludo::drawPiece(int boxnum)
{
	int x;
	int y;
	grid.GetBoxCenter(boxnum, y, x);

	MyColor c;
	switch (Plyturn+1)
	{
	case 1:
		c = Blue;
		break;
	case 2:
		c = Red;
		break;
	case 3:
		c = Green;
		break;
	case 4:
		c = Brown;
		break;
	}
	setcolor(c);
	if(c != Brown)
		setfillstyle(SOLID_FILL, c + 8);
	else
		setfillstyle(SOLID_FILL, Yellow);
	circle(y, x, 15);
	floodfill(y, x, c);
}

void Ludo::undrawPiece(int boxnum)
{
	grid.Redraw(boxnum);
}

Ludo::Ludo()
{
	//
	//	/*int CA[] = { Magenta, LitMagenta, White, Red, LitRed, White, Green, LitGreen, White, Cyan, LitCyan, White };
	//	Grid Ludo(4, Max_Rows, Max_Cols, CA, 0);*/
	//light mode

	int CA[] = { LitBlue,Blue,  Black,  LitRed, Red,Black, LitGreen, Green, Black, Yellow, Brown, Black };
	grid = Grid(4, 800, 1000, CA, 15);
	//dark mode
}

void Ludo::storeDiceRoll(int n)
{
	DiceRolls.push_back(n);
}

int Ludo::getVersion()
{
	return Ver;
}
void Ludo::setVersion(int v)
{
  Ver = v;
}
void Ludo::ChangeTurn()
{
	if (Plyturn < Ver - 1)
		Plyturn++;
	else
		Plyturn = 0;
}
void Ludo::PrintTurnMsg()
{
	cout << "\nPlayer " << Plyturn + 1 << " Turn\n";
}
int Ludo::Rolldice()
{
	int D;
	D = (rand() % 6) + 1;
	return D;
}
void Ludo::SelectPiece()
{
	cin >> S.boxnum;
}
bool Ludo::IsValidSelection()
{
	if (Boxes[S.boxnum]->PiecesHere.size() == 0)
		return false;

	int nop = Boxes[S.boxnum]->PiecesHere.size();

	for (int i = 0; i < nop; i++)
	{
		if (Boxes[S.boxnum]->PiecesHere[i]->color == Players[Plyturn]->color)
			return true;
	}

}
bool Ludo::IsValidDestination()
{
	return true;
}

void Ludo::getAllDiceRolls()
{
	int n = 0;
	do
	{
		char c;
		if (n == 6)
			cout << "\nRoll again...! ";
		cout << "\nEnter D to roll dice: ";
		cin >> c;
		if (c == 'd')
		{
			n = Rolldice();
			cout << "\nDice : " << n << "\n";
			storeDiceRoll(n);
		}
	} while (n == 6);
}

bool Ludo::IsVacantSpot()
{
	if (Boxes[E.boxnum]->PiecesHere.size() == 0)
		return true;
	else
		return false;
}
void Ludo::RemovePlayer()
{	
	Players.erase(Players.begin() + Plyturn);
}
Piece* Ludo::getSelectedPiece(int bn)
{
	return Players[Plyturn]->Pieces[0];
}

bool Ludo::iskill()
{
	return false;
}
void Ludo::init(int NOP)
{

	COLOUR c[] = { blue,red,green,brown,purple,orange };
	int pos[] = { 9,22,35,48, 61,74 };

	if (NOP != 2)
	{
		for (int i = 0; i < NOP; i++)
		{
			Player* ptr = new Player(c[i], pos[i]);
			Players.push_back(ptr);
		}
	}
	else if (NOP == 2)
	{
		Player* ptr = new Player(c[0], pos[0]);
		Players.push_back(ptr);
		Player* ptr2 = new Player(c[2], pos[2]);
		Players.push_back(ptr2);
	}

	for (int bi = 0; bi < 53; bi++)
	{
		Box* b = new Box(bi + 1);
		Boxes.push_back(b);
	}

}
void Ludo::Update()
{

}
void Ludo::Highlight()
{

}
void Ludo::UnHighlight()
{

}
void Ludo::DisplayBoard()
{

}
void Ludo::AddWinnerToList(Player* Won)
{
	PlayersWon.push_back(Won);	
}

void Ludo::play()
{
	initwindow(1000, 800, "Ludo");
	grid.PrintGrid();
	srand(time(0));
	int NOP; 
	cout << "Enter no. of Players: ";
	cin >> NOP;
	init(NOP);

	DisplayBoard();
	Plyturn = 0;
	do
	{
		PrintTurnMsg();

		getAllDiceRolls();

		cout << "\nDice rolls: ";
		for (int i = 0; i < DiceRolls.size(); i++)
			cout << DiceRolls[i] << " ";


		int c = 0;
		do
		{
			int bn;
			do
			{

				//get box number
			} while (!IsValidSelection());

			Highlight();


			do
			{
				int boxnum;
				cin >> boxnum;
			} while (IsValidDestination());

			UnHighlight();
			Update();
			c++;
		} while (c < DiceRolls.size());
		
		if (Players[Plyturn]->Pieces.size() == 0)
		{
			AddWinnerToList(Players[Plyturn]);
			RemovePlayer();
		}

		ChangeTurn();

	} while (Players.size() > 1);
}
