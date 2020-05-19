#include "Ludo.h"
#include "Piece.h"
#include "Player.h"
#include"Box.h"
#include"Grid.h"
#include<time.h>

//enum MyColor {
//	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGay = 7, DarkGray = 8,
//	LitBlue = 9, LitGreen = 10, LitCyan = 11, LitRed = 12, LitMagenta = 13, Yellow = 14, White = 15
//};
//void Ludo::drawPiece(int boxnum)
//{
//	int x;
//	int y;
//	grid.GetBoxCenter(boxnum, x, y);
//
//	MyColor c;
//	switch (Plyturn+1)
//	{
//	case 1:
//		c = Blue;
//		break;
//	case 2:
//		c = Red;
//		break;
//	case 3:
//		c = Green;
//		break;
//	case 4:
//		c = Brown;
//		break;
//	}
//	setcolor(c);
//	if(c != Brown)
//		setfillstyle(SOLID_FILL, c + 8);
//	else
//		setfillstyle(SOLID_FILL, Yellow);
//	circle(y, x, 15);
//	floodfill(y, x, c);
//}
//
//void Ludo::undrawPiece(int boxnum)
//{
//	int t = Plyturn;
//	grid.Redraw(boxnum); bool drawn = false;
//
//	for (int i = 0; i < Boxes[boxnum - 1]->PiecesHere.size(); i++)
//	{
//		drawn = false;
//		for (int j = 0; j < Ver && drawn == false; j++)
//		{
//			Plyturn = j;
//			if (Players[Plyturn]->color == Boxes[boxnum - 1]->PiecesHere[i]->color)
//				drawPiece(Boxes[boxnum - 1]->PiecesHere[i]->position.boxnum), drawn = true;
//		}
//	}
//	Plyturn = t;
//}
//
//Ludo::Ludo()
//{
//	//
//	//	/*int CA[] = { Magenta, LitMagenta, White, Red, LitRed, White, Green, LitGreen, White, Cyan, LitCyan, White };
//	//	Grid Ludo(4, Max_Rows, Max_Cols, CA, 0);*/
//	//light mode
//
//	int CA[] = { LitBlue,Blue,  Black,  LitRed, Red,Black, LitGreen, Green, Black, Yellow, Brown, Black };
//	
//	grid = Grid(4, 800, 1000, CA, 15);
//	//dark mode
//}
//void Ludo::storeDiceRoll(int n)
//{
//	DiceRolls.push_back(n);
//}
//
//int Ludo::getVersion()
//{
//	return Ver;
//}
//void Ludo::setVersion(int v)
//{
//  Ver = v;
//}
//void Ludo::ChangeTurn()
//{
//	if (Plyturn < Ver - 1)
//		Plyturn++;
//	else
//		Plyturn = 0;
//}
//void Ludo::PrintTurnMsg()
//{
//	cout << "\nPlayer " << Plyturn + 1 << " Turn\n";
//}
//int Ludo::Rolldice()
//{
//	int D;
//	D = (rand() % 6) + 1;
//	return D;
//}
//void Ludo::SelectPiece()
//{
//	cin >> S.boxnum;
//}
//bool Ludo::IsValidSelection()
//{
//	if (Boxes[S.boxnum-1]->PiecesHere.size() == 0)
//		return false;
//
//	int nop = Boxes[S.boxnum-1]->PiecesHere.size();
//
//	for (int i = 0; i < nop; i++)
//	{
//		if (Boxes[S.boxnum-1]->PiecesHere[i]->color == Players[Plyturn]->color)
//			return true;
//	}
//
//	return false;
//}
//bool Ludo::IsValidDestination(int c)
//{
//	int jump = S.boxnum + DiceRolls[c];  // 48 + 6 = 54
//
//	if (jump > grid.NumberOfHmes * 13) // 54 > 52 == true
//	{
//		jump = jump - grid.NumberOfHmes * 13; // jump = 54 - 52 = 2
//		if (grid.NumberOfHmes * 13 - S.boxnum + jump == DiceRolls[c]) // 52 - 48 +  2 = 6
//			return true;
//	}
//
//	if (E.boxnum - S.boxnum == DiceRolls[c]) // 52 - 48 +  2 = 6
//		return true;
//	return false;
//}
//
//void Ludo::getAllDiceRolls()
//{
//	int n = 6; int x, y;
//	do
//	{
//		do
//		{
//			clearmouseclick(WM_LBUTTONDOWN);
//			do
//			{
//			} while (!ismouseclick(WM_LBUTTONDOWN));
//			getmouseclick(WM_LBUTTONDOWN, y, x);
//		} while (!(isDiceClicked(x, y)));
//		
//	
//		grid.Dice(6, 450, 1000, 40, 0);
//		grid.Dice(5, 450, 1000, 40, 0);
//		
//		n = Rolldice();
//		cout << "\nDice : " << n << "\n";
//		storeDiceRoll(n);
//
//		grid.Dice(n, 450, 1000, 40, 15);
//	} while (n == 6);
//
//}
//
//bool Ludo::IsVacantSpot(Position p)
//{
//	if (Boxes[p.boxnum]->PiecesHere.size() == 0)
//		return true;
//	else
//		return false;
//}
//void Ludo::RemovePlayer()
//{	
//	Players.erase(Players.begin() + Plyturn);
//}
//Piece* Ludo::getSelectedPiece(int bn)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (Players[Plyturn]->color == Boxes[bn - 1]->PiecesHere[i]->color)
//			return Boxes[bn - 1]->PiecesHere[i];
//	}
//	return nullptr;
//}
//
//void Ludo::move()
//{
//	
//}
//bool Ludo::isDiceClicked(int row, int col)
//{
//	if ((col >= 960 && col <= 1040) && (row >= 410 && row <= 490))
//		return true;
//	return false;
//}
//bool Ludo::iskill(Box* ep)
//{
//	if (ep->isSafeSpot == true) return false;
//
//	else if ((ep->PiecesHere.empty())) return false;
//	//same colored piece
//	for (int pc = 0; pc < 4; pc++)
//		if (ep->position.boxnum == Players[Plyturn]->Pieces[pc]->position.boxnum) return false;
//
//	return true;
//}
//void Ludo::kill()
//{
//	//curr box -> remove 
//	//start box -> add
//
//	Piece* t = Boxes[E.boxnum - 1]->PiecesHere[0];
//	COLOUR c = Boxes[E.boxnum - 1]->PiecesHere[0]->color;
//
//	Boxes[E.boxnum - 1]->PiecesHere.erase(Boxes[E.boxnum - 1]->PiecesHere.begin());
//
//	int ci;
//	for (int i = 0; i < Ver; i++)
//	{
//		if (Players[i]->color == c)
//			ci = i;
//	}
//	t->position = Players[ci]->startPos.boxnum;
//	Boxes[Players[ci]->startPos.boxnum - 1]->PiecesHere.push_back(t);
//
//}
//void Ludo::init(int NOP)
//{
//	int NOB=0; // For Boxes initialization.
//	COLOUR c[] = { blue,red,green,brown, cyan, magenta};
//	int pos[] = { 9,22,35,48, 61,74 };
//
//	if (NOP != 2)
//	{
//		for (int i = 0; i < NOP; i++)
//		{
//			Player* ptr = new Player(c[i], pos[i]);
//			Players.push_back(ptr);
//			NOB = 13 * grid.NumberOfHmes + 5 * grid.NumberOfHmes;
//		}
//	}
//	else if (NOP == 2)
//	{
//		Player* ptr = new Player(c[0], pos[0]);
//		Players.push_back(ptr);
//		Player* ptr2 = new Player(c[2], pos[2]);
//		Players.push_back(ptr2);
//
//		NOB = 13 * grid.NumberOfHmes + 5*grid.NumberOfHmes;
//	}
//	// Safe Box Positions: 4 9 17 22 30 35 43 48 56 61 69 74
//	for (int bi = 0; bi < NOB; bi++)
//	{
//		bool isSafe = false;
//		if (bi == 3 || bi == 8 || bi == 16 || bi == 21 || bi == 29 || bi == 34 || bi == 42
//			|| bi == 47 || bi == 55 || bi == 60 || bi == 68 || bi == 73 || bi > 13*grid.NumberOfHmes - 1)
//			isSafe = true;
//
//		Box* b = new Box(bi + 1,isSafe);
//		Boxes.push_back(b);
//		for (int i = 0; i < NOP; i++)
//		{
//			if (pos[i] == bi + 1)
//			{
//				for(int j = 0; j < 4; j++)
//					Boxes[bi]->PiecesHere.push_back(Players[i]->Pieces[j]);
//			}
//		}
//	}
//
//}
//void Ludo::Update(Piece* p)
//{
//	Boxes[E.boxnum - 1]->PiecesHere.push_back(p);
//	Boxes[E.boxnum - 1]->PiecesHere[Boxes[E.boxnum - 1]->PiecesHere.size() - 1]->position = E.boxnum;
//
//	int c = 0;
//	while (Boxes[S.boxnum - 1]->PiecesHere[c] != p)
//		c++;
//
//	Boxes[S.boxnum - 1]->PiecesHere.erase(Boxes[S.boxnum - 1]->PiecesHere.begin() + c);
//	
//	undrawPiece(S.boxnum);
//	drawPiece(E.boxnum);
//}
//
//void Ludo::AddWinnerToList(Player* Won)
//{
//	PlayersWon.push_back(Won);	
//}
//
//void Ludo::play()
//{
//	initwindow(1200, 800, "Ludo");
//	
//	grid.PrintGrid();
//	srand(time(0));
//	int NOP; 
//	
//	cout << "Enter no. of Players: ";
//	cin >> NOP;
//	
//	init(NOP);
//	int x, y;
//
//	Plyturn = 0;
//	Ver = NOP;
//
//	grid.Dice(6, 450, 1000, 40, 15);
//	do
//	{
//		PrintTurnMsg();
//
//		getAllDiceRolls();
//
//		cout << "\nDice rolls: ";
//		for (int i = 0; i < DiceRolls.size(); i++)
//			cout << DiceRolls[i] << " ";
//
//		
//
//		Piece* currPiece;
//
//		int c = 0;
//		do
//		{
//			int bn;
//			do
//			{
//				clearmouseclick(WM_LBUTTONDOWN);
//				do
//				{
//				} while (!ismouseclick(WM_LBUTTONDOWN));
//				getmouseclick(WM_LBUTTONDOWN, y, x);
//				if (grid.IsBox(x, y))
//				{
//					S.boxnum = grid.BoxNumber(x, y); 
//				}
//			} while (!IsValidSelection());
//
//			currPiece = getSelectedPiece(S.boxnum);
//
//			do
//			{
//				clearmouseclick(WM_LBUTTONDOWN);
//				do
//				{
//				} while (!ismouseclick(WM_LBUTTONDOWN));
//				getmouseclick(WM_LBUTTONDOWN, y, x);
//				if (grid.IsBox(x, y))
//				{
//					E.boxnum = grid.BoxNumber(x, y);
//				}
//			} while (!IsValidDestination(c));
//			
//
//			if (iskill(Boxes[E.boxnum - 1]))
//			{
//				kill();
//				currPiece->hasKilled = true;
//			}
//
//			Update(currPiece);
//
//			c++;
//
//		} while (c < DiceRolls.size());
//
//		DiceRolls.clear();
//		
//		if (Players[Plyturn]->Pieces.size() == 0)
//		{
//			AddWinnerToList(Players[Plyturn]);
//			RemovePlayer();
//		}
//
//		ChangeTurn();
//
//	} while (Players.size() > 1);
//}
enum MyColor {
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGay = 7, DarkGray = 8,
	LitBlue = 9, LitGreen = 10, LitCyan = 11, LitRed = 12, LitMagenta = 13, Yellow = 14, White = 15
};
void Ludo::drawPiece(int boxnum)
{
	int x;
	int y;
	grid.GetBoxCenter(boxnum, x, y);

	MyColor c;
	switch (Plyturn + 1)
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
	if (c != Brown)
		setfillstyle(SOLID_FILL, c + 8);
	else
		setfillstyle(SOLID_FILL, Yellow);
	circle(y, x, 15);
	floodfill(y, x, c);
}

void Ludo::undrawPiece(int boxnum)
{
	int t = Plyturn;
		grid.Redraw(boxnum); bool drawn = false;
	
		for (int i = 0; i < Boxes[boxnum - 1]->PiecesHere.size(); i++)
		{
			drawn = false;
			for (int j = 0; j < Ver && drawn == false; j++)
			{
				Plyturn = j;
				if (Players[Plyturn]->color == Boxes[boxnum - 1]->PiecesHere[i]->color)
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
//bool IsValidSum(int Vs[] , int V_Sum, int Adds)
//{
//
//}
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
	//int jump= S.boxnum + DiceRolls[c];  // 48 + 6 = 54

	//if (jump > grid.NumberOfHmes * 13) // 54 > 52 == true
	//{
	//	jump = jump - grid.NumberOfHmes * 13; // jump = 54 - 52 = 2
	//	if (grid.NumberOfHmes * 13 - S.boxnum + jump == DiceRolls[c]) // 52 - 48 +  2 = 6
	//		return true;
	//}
	//
	//if (E.boxnum - S.boxnum == DiceRolls[c]) // 52 - 48 +  2 = 6
	//	return true;
	if (!currPiece->isOut)
	{
		if (NumberAt(6, &DiceRolls[0], DiceRolls.size()) != -1)
		{
			if (S.boxnum == E.boxnum)
			{
				DiceRolls.erase(DiceRolls.begin() + NumberAt(6, &DiceRolls[0], DiceRolls.size()));   c--;
				return true;
			}
			DiceRolls.erase(DiceRolls.begin() + NumberAt(6, &DiceRolls[0], DiceRolls.size()));   c--;
			currPiece->bringOut();
		}
		else return false;
	}
	if (E.boxnum < S.boxnum)
	{
		return  ((13 * grid.NumberOfHmes - S.boxnum + E.boxnum)) == DiceRolls[DiceRolls.size() - 1];
	}
	if (E.boxnum - S.boxnum == DiceRolls[DiceRolls.size() - 1]) return true;
	return false;
}

void Ludo::getAllDiceRolls()
{
	int n = 6; int x, y;
	do
	{
		do
		{
			clearmouseclick(WM_LBUTTONDOWN);
			do
			{
			} while (!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, y, x);
		} while (!(isDiceClicked(x, y)));


		grid.Dice(6, 450, 1000, 40, 0);
		grid.Dice(5, 450, 1000, 40, 0);

		n = Rolldice();
		cout << "\nDice : " << n << "\n";
		storeDiceRoll(n);

		grid.Dice(n, 450, 1000, 40, 15);
	} while (n == 6);

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
	for (int i = 0; i < 4; i++)
	{
		if (Players[Plyturn]->color == Boxes[bn - 1]->PiecesHere[i]->color)
			return Boxes[bn - 1]->PiecesHere[i];
	}
	return nullptr;
}

void Ludo::move()
{

}
bool Ludo::isDiceClicked(int row, int col)
{
	if ((col >= 960 && col <= 1040) && (row >= 410 && row <= 490))
		return true;
	return false;
}
bool Ludo::iskill(Box* ep)
{
	/*if (IsVacantSpot(ep->position))
		return false;*/

	if (ep->isSafeSpot == true) return false;

	else if ((ep->PiecesHere.empty())) return false;
	//same colored piece
	for (int pc = 0; pc < 4; pc++)
		if (ep->position.boxnum == Players[Plyturn]->Pieces[pc]->position.boxnum) return false;

	

	return true;
}
void Ludo::kill()
{
	//curr box -> remove 
	//start box -> add

	Piece* t = Boxes[E.boxnum - 1]->PiecesHere[0];
	COLOUR c = Boxes[E.boxnum - 1]->PiecesHere[0]->color;

	Boxes[E.boxnum - 1]->PiecesHere.erase(Boxes[E.boxnum - 1]->PiecesHere.begin());

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
	return Boxnum == (grid.NumberOfHmes * 13 + ((Plyturn + 1) * 5) + 1);
}
void Ludo::Update(Piece* p)
{
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
	if (!p->isOut)p->bringOut();
	undrawPiece(S.boxnum);
	if (!IsWin(E.boxnum))
		drawPiece(E.boxnum);
	else
	{
		for (int i = 0; i < Players[Plyturn]->Pieces.size(); i++) if (Players[Plyturn]->Pieces[i] == p) Players[Plyturn]->removePiece(i);
	}

}

void Ludo::AddWinnerToList(Player* Won)
{
	PlayersWon.push_back(Won);
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
	Plyturn = 0;
	Ver = NOP;
	grid.Dice(6, 450, 1000, 40, 15);
	do
	{
		PrintTurnMsg();

		getAllDiceRolls();

		string DR;
		for (int i = 0; i < DiceRolls.size(); i++)
			DR += DiceRolls[i] + 48;
		outtextxy(1000, 500, &DR[0]);

		if (Players[Plyturn]->Pieces.size() == Boxes[Plyturn * 13 + 9 - 1]->PiecesHere.size())
		{
			S.boxnum = (Plyturn * 13 + 9);
			if (!IsValidSelection())
			{
				ChangeTurn();
				DiceRolls.clear();
				continue;
			}
		}

		cout << "\nDice rolls: ";
		for (int i = 0; i < DiceRolls.size(); i++)
			cout << DiceRolls[i] << " ";
		currPiece;
		
		int c = 0;
		do
		{
			int bn;
			do
			{
				do
				{
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
			do
			{
				clearmouseclick(WM_LBUTTONDOWN);
				do
				{
				} while (!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN, y, x);
				E.boxnum = grid.BoxNumber(x, y);

			} while (!(grid.IsBox(x, y) && IsValidDestination(c)));

			
			if (iskill(Boxes[E.boxnum - 1]))
			{
				kill();
				currPiece->hasKilled = true;
			}
			
			if (currPiece->isOut)
				c++;
			Update(currPiece);
			if (E.boxnum != S.boxnum) 
				DiceRolls.pop_back();


		} while (DiceRolls.size());
		DiceRolls.clear();
		if (Players[Plyturn]->Pieces.size() == 0)
		{
			AddWinnerToList(Players[Plyturn]);
			RemovePlayer();
		}
		ChangeTurn();

	} while (Players.size() > 1);
}
