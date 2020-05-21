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
void Ludo::drawPiece(int boxnum, bool IsOut, int p_num, bool Isinnercolor)
{
	int x;
	int y;
	if (IsOut)
		grid.GetBoxCenter(boxnum, x, y);
	else
		grid.GetBoxCenterOnHome(p_num, Plyturn + 1, x, y);

	int c = grid.HomeColors[Plyturn * 3 + !Isinnercolor];
	setcolor(c);
	setfillstyle(SOLID_FILL, c + 8 * (!Isinnercolor) - 8 * (Isinnercolor));
	//	setfillstyle(SOLID_FILL, c);
	circle(y, x, 15);

	floodfill(y, x, c);

	//	else floodfill(y, x, c);

}

void Ludo::undrawPiece(int boxnum)
{
	grid.Redraw(boxnum); bool drawn; int t = Plyturn;
	for (int i = 0; i < Boxes[boxnum - 1]->PiecesHere.size(); i++)
	{
		drawn = false;
		for (int j = 0; j < Ver && drawn == false; j++)
		{
			Plyturn = j;
			if ((Players[Plyturn]->color == Boxes[boxnum - 1]->PiecesHere[i]->color) && Boxes[boxnum - 1]->PiecesHere[i]->isOut)
				drawPiece(Boxes[boxnum - 1]->PiecesHere[i]->position.boxnum), drawn = true;
		}
	}
	Plyturn = t;
}

Ludo::Ludo()
{
	//
	//	/*int CA[] = { Magenta, LitMagenta, White, Red, LitRed, White, Green, LitGreen, White, Cyan, LitCyan, White };
	//	Grid Ludo(4, Max_Rows, Max_Cols, CA, 0);*/
	//light mode

	int CA[] = { LitBlue,Blue,  Black,  LitRed, Red,Black, LitGreen, Green, Black, Yellow, Brown, Black };

	grid = Grid(4, 700, 1000, CA, 15);
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
	if (Plyturn < Players.size() - 1)
		Plyturn++;
	else
		Plyturn = 0;
}
void Ludo::PrintTurnMsg()
{
	string col;
	switch (Plyturn)
	{
	case 0:
		col = "Blue"; break;
	case 1:
		col = "Red"; break;
	case 2: 
		col = "Green"; break;
	case 3:
		col = "Yellow"; break;
	}

	cout << "\n\n" << col << "'s Turn "; /*<< Players[Plyturn]->Pieces.size() << " ";
	for (int i = 0; i < Players[Plyturn]->Pieces.size(); i++)
		cout << "("
		<< "" << ((Players[Plyturn]->Pieces[i]->isOut) ? "O" : "N_O")
		<< " " << Players[Plyturn]->Pieces[i]->position.boxnum
		<< " " << ((Players[Plyturn]->Pieces[i]->isSafe) ? "S" : "N_S")
		<< " " << ((Players[Plyturn]->Pieces[i]->hasKilled) ? "K" : "N_K")
		<< ") ";*/



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
bool IsNumber(int Num, vector<int>::iterator Vs, int size)
{

	for (int i = 0; i < size; i++)
	{
		if (Vs[i] == Num) return true;
	}
	return false;
}
int NumberAt(int Num, int Vs[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (Vs[i] == Num) return i;
	}
	return -1;
}

void BinaryCounter(bool* Bptr, int size)
{
	int i = 0;
	for (i = size - 1; Bptr[i]; i--)
	{
		Bptr[i] = 0;
	}
	Bptr[i] = 1;
}
int Ludo::SumOfDiceBinaryIndexs(bool* bptr, int B_size)
{
	int Sum = 0;
	for (int i = 0; i < B_size; i++)
	{
		if (bptr[i])Sum += DiceRolls[i];
	}
	return Sum;
}
void Ludo::CalcValidSumindexes(int Sum)
{
	int DR_Size = DiceRolls.size();
	DiceSumIndexes.clear();
	int m_Sum = 0;
	for (int i = 0; i < DR_Size; i++) m_Sum += DiceRolls[i];
	if (m_Sum < Sum)  return;                      //return false;
	if (m_Sum == Sum)
	{
		for (int i = 0; i < DiceRolls.size(); i++)
		{
			DiceSumIndexes.push_back(i);
		}
		return;
	}


	//	if(DiceSumIndexes.size()!=0)DiceSumIndexes.clear();
	bool* BD_i = new bool[DiceRolls.size()]{ 0 };     //000
	BinaryCounter(BD_i, DiceRolls.size());       //001
	int Exp = 1;
	for (int pi = 0; pi < DiceRolls.size(); pi++)Exp *= 2;
	Exp -= 2;
	for (int i = 0; i < Exp; i++)
	{
		if (SumOfDiceBinaryIndexs(BD_i, DiceRolls.size()) == Sum)
		{
			for (int i = 0; i < DiceRolls.size(); i++)
			{
				if (BD_i[i]) DiceSumIndexes.push_back(i);
			}
			return;
		}
		BinaryCounter(BD_i, DiceRolls.size());
	}

}
bool Ludo::IsValidSelection()
{
	if (Boxes[S.boxnum - 1]->PiecesHere.size() == 0)
		return false;

	int nop = Boxes[S.boxnum - 1]->PiecesHere.size();

	for (int i = 0; i < nop; i++)
	{
		if (Boxes[S.boxnum - 1]->PiecesHere[i]->color == Players[Plyturn]->color && ((IsNumber(6, DiceRolls.begin(), DiceRolls.size())) || Boxes[S.boxnum - 1]->PiecesHere[i]->isOut))
			return true;
	}
	return false;
}
bool Ludo::CanMov(Piece* Pce, int B_E)
{
	Pce->position.boxnum;
	if (Pce->isOut)
	{

		grid.NumberOfHmes * 13 + ((Plyturn + 1) * 5) + 1;
		Plyturn;
	}
	return 0;
}
bool Ludo::IsValidDestination(int c)
{
	if (!currPiece->isOut)
	{
		if (NumberAt(6, &DiceRolls[0], DiceRolls.size()) != -1)
		{
			if (S.boxnum == E.boxnum)
			{
				return true;
			}
		}
		else return false;
	}

	if (E.boxnum < S.boxnum)
	{
		return  ((13 * grid.NumberOfHmes - S.boxnum + E.boxnum)) == DiceRolls[DiceRolls.size() - 1];
	}
	if ((E.boxnum - S.boxnum == DiceRolls[DiceRolls.size() - 1]) && !IsWin(E.boxnum))
	{ return true; }
	if (E.boxnum > (13 * grid.NumberOfHmes))
	{
		if (!currPiece->hasKilled) return 0;
		if (IsWin(E.boxnum))
		{
			if (S.boxnum <= (13 * Plyturn + 7))
			{
				return ((((13 * Plyturn + 7) - S.boxnum) + 6) == DiceRolls[DiceRolls.size() - 1]);
			}
			if (S.boxnum > (13 * grid.NumberOfHmes + Plyturn * 5)) 
			{
				return ((13 * grid.NumberOfHmes + Plyturn * 5) + 6 - S.boxnum) == DiceRolls[DiceRolls.size() - 1]; 
			}
		}
		if ((Players[Plyturn]->startPos.boxnum + 4) / 13 == ((((E.boxnum - 13 * grid.NumberOfHmes) - 1) / 5) + 1))
		{
			if (S.boxnum <= (Players[Plyturn]->startPos.boxnum - 2))
			{
				return DiceRolls[DiceRolls.size() - 1] == ((Players[Plyturn]->startPos.boxnum - 2) - S.boxnum + E.boxnum - (13 * grid.NumberOfHmes + Plyturn * 5));
			}
		}
	}
	return false;
}

void Ludo::getAllDiceRolls()
{
	int n = 6; int x, y; bool dice = false, cheat = false;
	string DR;
	do
	{
		clearmouseclick(WM_LBUTTONDOWN);
		do
		{
		} while (!ismouseclick(WM_LBUTTONDOWN));
		getmouseclick(WM_LBUTTONDOWN, y, x);

		if (isDiceClicked(x, y))
			dice = true;
		else if (isCheatClicked(x, y))
			cheat = true;
	} while (!cheat && !dice);

	//if cheat clicked then cheat dice rolls
	if (cheat)
	{
		cout << "\nEnter dice rolls :";
		int ni;
		do
		{
			cin >> ni;
			DiceRolls.push_back(ni);
		} while (ni == 6);
	}
	//if dice clicked then get dice rolls from dice
	else
	{
		do
		{

			grid.Dice(6, 450, 1000, 40, 0);
			grid.Dice(5, 450, 1000, 40, 0);

			n = Rolldice();
			storeDiceRoll(n);
			DR += n + 48; DR += ' ';
			outtextxy(1000, 500, &DR[0]);
			cout << "\nDice : " << n << "\n";

			grid.Dice(n, 450, 1000, 40, 15);

			if (n == 6)
			{
				do
				{
					clearmouseclick(WM_LBUTTONDOWN);
					do
					{
					} while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, y, x);
				} while (!(isDiceClicked(x, y)));
			}

		} while (n == 6);
	}
}

bool Ludo::IsVacantSpot(Position p)
{
	if (Boxes[p.boxnum]->PiecesHere.size() == 0)
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
	for (int i = 0; i < Boxes[bn - 1]->PiecesHere.size(); i++)
	{
		if (Players[Plyturn]->color == Boxes[bn - 1]->PiecesHere[i]->color)
			return Boxes[bn - 1]->PiecesHere[i];
	}
	return nullptr;
}

bool Ludo::isDiceClicked(int row, int col)
{
	if ((col >= 960 && col <= 1040) && (row >= 410 && row <= 490))
		return true;
	return false;
}
void Ludo::cheatButton()
{
	setcolor(1);
	setfillstyle(SOLID_FILL, 4);
	
	rectangle(1000 - 50, 200- 40, 1000 + 50, 200 + 40);
	floodfill(1000, 200, 1);

	setbkcolor(4);
	setcolor(15);
	outtextxy(1000 - 30, 200 - 8, "C H E A T");
	setbkcolor(0);

}
bool Ludo::isCheatClicked(int row, int col)
{
	if ((col >= 1000-50 && col <= 1000+50) && (row >= 200-40 && row <= 200+40))
		return true;
	return false;
}
bool Ludo::iskill()
{
	if (Boxes[E.boxnum - 1]->isSafeSpot == true) return false;

	else if ((Boxes[E.boxnum - 1]->PiecesHere.empty())) return false;
	if (Boxes[E.boxnum - 1]->PiecesHere.size() > 1)       return false;
	return (Boxes[E.boxnum - 1]->PiecesHere[0]->color != Players[Plyturn]->color);
}
void Ludo::kill()
{
	Piece* t = Boxes[E.boxnum - 1]->PiecesHere[0];
	COLOUR c = Boxes[E.boxnum - 1]->PiecesHere[0]->color;

	Boxes[E.boxnum - 1]->PiecesHere.erase(Boxes[E.boxnum - 1]->PiecesHere.begin());

	t->isOut = 0; t->hasKilled = 0; t->isSafe = 1;
	int ci;
	for (int i = 0; i < Ver; i++)
	{
		if (Players[i]->color == c)
			ci = i;
	}
	t->position = Players[ci]->startPos.boxnum;
	Boxes[Players[ci]->startPos.boxnum - 1]->PiecesHere.push_back(t);
}
bool IsSafeBoxNumber(int Bn)
{
	Bn = Bn % 13;
	return (Bn == 4 || Bn == 9);
}
void Ludo::init(int NOP)
{
	int NOB = 0; // For Boxes initialization.
	COLOUR c[] = { blue,red,green,brown, cyan, magenta };
	int pos[] = { 9,22,35,48, 61,74 };

	if (NOP != 2)
	{
		for (int i = 0; i < NOP; i++)
		{
			Player* ptr = new Player(c[i], pos[i]);
			Players.push_back(ptr);
			NOB = 13 * grid.NumberOfHmes + 5 * grid.NumberOfHmes;
		}
	}
	else if (NOP == 2)
	{
		Player* ptr = new Player(c[0], pos[0]);
		Players.push_back(ptr);
		Player* ptr2 = new Player(c[2], pos[2]);
		Players.push_back(ptr2);

		NOB = 13 * grid.NumberOfHmes + 5 * grid.NumberOfHmes;
	}
	// Safe Box Positions: 4 9 17 22 30 35 43 48 56 61 69 74
	for (int bi = 0; bi < NOB; bi++)
	{
		bool isSafe = false;
		//if (bi == 4 || bi == 9 || bi == 17 || bi == 22 || bi == 30 || bi == 35 || bi == 43
		//	|| bi == 48 || bi == 56 || bi == 61 || bi == 69 || bi == 74)
		if (IsSafeBoxNumber(bi + 1))
			isSafe = true;
		else if (bi >= 13 * grid.NumberOfHmes)
			isSafe = true;
		Box* b = new Box(bi + 1, isSafe);
		Boxes.push_back(b);
		for (int i = 0; i < NOP; i++)
		{
			if (pos[i] == bi + 1)
			{
				for (int j = 0; j < 4; j++)
					Boxes[bi]->PiecesHere.push_back(Players[i]->Pieces[j]);
			}
		}
	}
}
bool Ludo::IsWin(int Boxnum)
{
	return Boxnum == (13 * grid.NumberOfHmes + 5 * grid.NumberOfHmes + 1);
}
void Ludo::Update(Piece* p)
{
	if (IsWin(E.boxnum))
	{

	}
	if (S.boxnum != E.boxnum)
	{
		if (!IsWin(E.boxnum))
		{
			Boxes[E.boxnum - 1]->PiecesHere.push_back(p);
			Boxes[E.boxnum - 1]->PiecesHere[Boxes[E.boxnum - 1]->PiecesHere.size() - 1]->position = E.boxnum;
		}
		int c = 0;
		while (Boxes[S.boxnum - 1]->PiecesHere[c] != p)
			c++;
		Boxes[S.boxnum - 1]->PiecesHere.erase(Boxes[S.boxnum - 1]->PiecesHere.begin() + c);
	}
	if (!p->isOut)
	{

		int count = 0;
		for (int ci = 0; ci < Players[Plyturn]->Pieces.size(); ci++) { if (!Players[Plyturn]->Pieces[ci]->isOut) count++; }
		p->bringOut();
		{
			int r = 0, c = 0;
			grid.GetBoxCenterOnHome(5 - count, Plyturn + 1, r, c);
			grid.PrintHomeColor(r, c, Plyturn + 1, 20, 0);
			grid.PrintHomeColor(r, c, Plyturn + 1, 20, 1);
		}

	}
	//	else
	undrawPiece(S.boxnum);
	if (!IsWin(E.boxnum))
		drawPiece(E.boxnum);
	else
	{
		for (int i = 0; i < Players[Plyturn]->Pieces.size(); i++) if (Players[Plyturn]->Pieces[i] == p) Players[Plyturn]->removePiece(i);
	}

}
void Ludo::Highlight()
{
	setlinestyle(SOLID_LINE, 0, 3);
	drawPiece(S.boxnum);
	setlinestyle(SOLID_LINE, 0, 1);
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
void Wait(int T)
{
	for (int i = 0; i < T * 1000000; i++)
	{
	}
}
void Ludo::play()
{
	initwindow(1200, 700, "Ludo");
	grid.PrintGrid();
	srand(time(0));
	int NOP;
	cout << "Enter no. of Players: ";
	cin >> NOP;
	init(NOP);
	int x, y;
	DisplayBoard();
	cheatButton();
	Plyturn = 0;
	Ver = NOP;
	grid.Dice(6, 450, 1000, 40, 15);
	do
	{
		PrintTurnMsg();

		grid.PrintHomeColor(400 - 50, 1000, Plyturn + 1, 30, 1);

		for (int i = 0; i < Players[Plyturn]->Pieces.size(); i++)
		{
			int bn = Players[Plyturn]->Pieces[i]->position.boxnum;
			if (Players[Plyturn]->Pieces[i]->isOut)
			{
				drawPiece(bn, 1, 0, 0);

			}
			else
				drawPiece(bn, 0, i + 1, 1);
		}

		getAllDiceRolls();
	
		string DR;
		for (int i = 0; i < DiceRolls.size(); i++)
		{
			DR += DiceRolls[i] + 48; DR += ' ';

		}
		DR += "      ";
		outtextxy(1000, 500, &DR[0]);
		
		cout << "\nDice rolls: ";
		for (int i = 0; i < DiceRolls.size(); i++)
			cout << DiceRolls[i] << " ";

		if (Players[Plyturn]->Pieces.size() == Boxes[Plyturn * 13 + 9 - 1]->PiecesHere.size())
		{
			S.boxnum = (Plyturn * 13 + 9);
			if (!IsValidSelection())
			{
				DiceRolls.clear();
				ChangeTurn();
				system("cls");
				Wait(200);
				continue;
			}
		}

		Players[Plyturn]->Pieces;

		currPiece;
		int c = 0;
		do
		{
			int bn;
			do
			{
				do {
					clearmouseclick(WM_LBUTTONDOWN);
					do
					{
					} while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, y, x);
					if (grid.IsBox(x, y))
					{
						S.boxnum = grid.BoxNumber(x, y);
					}
				} while (!grid.IsBox(x, y));
			} while (!IsValidSelection());
			currPiece = getSelectedPiece(S.boxnum);
			Highlight();
			do
			{
				clearmouseclick(WM_LBUTTONDOWN);
				do
				{
				} while (!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN, y, x);
				E.boxnum = grid.BoxNumber(x, y);
				//					cout <<"Center "<< E.boxnum << " ";
				if (grid.IsCenterBox(x, y))
					E.boxnum = 18 * grid.NumberOfHmes + 1;
			} while (!((grid.IsBox(x, y) || grid.IsCenterBox(x, y)) && IsValidDestination(c)));
			UnHighlight();
			if (!IsWin(E.boxnum) && iskill())
			{
				kill();
				currPiece->hasKilled = true;
			}
			if (currPiece->isOut)
				c++;
			else  DiceRolls.erase(DiceRolls.begin());
			Update(currPiece);
			if (E.boxnum != S.boxnum) DiceRolls.pop_back();


		} while (DiceRolls.size());
		DiceRolls.clear();
		if (Players[Plyturn]->Pieces.size() == 0)
		{
			AddWinnerToList(Players[Plyturn]);
			string col;
			switch (Plyturn)
			{
			case 0:
				col = "Blue"; break;
			case 1:
				col = "Red"; break;
			case 2:
				col = "Green"; break;
			case 3:
				col = "Yellow"; break;
			}
			cout << "\n " << col << " has won...!!";
			RemovePlayer();
		}
		ChangeTurn();
		system("cls");
	} while (Players.size() > 1);
	return;
}
