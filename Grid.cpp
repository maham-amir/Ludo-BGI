#include "Grid.h"
#include"graphics.h"
//enum MyColor{Black =0, Blue =1, Green =2, Cyan =3,Red =4, Magenta =5,Brown =6, LightGay =7,DarkGray =8, LitBlue =9,LitGreen =10, LitCyan =11, LitRed =12,LightMagenta =13,Yellow =14, White=15};
#include<iostream>
Grid::Grid(int NOHs, int Window_Rows, int Window_Cols, int* CA, int B_G_C)
	:row_center(-1 + Window_Rows / 2), col_center(-1 + Window_Cols / 2), NumberOfHmes(NOHs), B_B_C(B_G_C)
{
	int B_s = (NumberOfHmes == 4) ? 2 : 3;
	m_Box_Size = ((Window_Rows < Window_Cols) ? Window_Rows : Window_Cols) / ((B_s + 6) * 2 - 1) / 2;
	Shift = 0;
	Box_S = B_s;
	HomeColors = new int[3 * NOHs];
	if (CA != nullptr)
	{
		for (int Clri = 0; Clri < 3 * NOHs; Clri++)
			HomeColors[Clri] = CA[Clri];
	}
}
void NumtoRow(int& B_N);
void RotateCircle(int R_C, int C_C, int Radius, int color)
{
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	circle(C_C, R_C, Radius);
	floodfill(C_C, R_C, color);
}
void Grid::Dice(int Num, int R_C, int C_C, int Size, int color)
{
	int width = Size;
	int height = Size;

	setcolor(color);
	rectangle(C_C - Size, R_C - Size, C_C + Size, R_C + Size);

	switch (Num)
	{
	case 1:
		RotateCircle(R_C, C_C, 5, color);
		break;
	case 2:
		RotateCircle(R_C, C_C + (width / 2) * .8, 5, color);
		RotateCircle(R_C, C_C - (width / 2) * .8, 5, color);
		break;

	case 3:
		RotateCircle(R_C - (height / 2) * .8, C_C - (width / 2) * .8, 5, color);   // t_left	
		RotateCircle(R_C, C_C, 5, color);
		RotateCircle(R_C + (height / 2) * .8, C_C + (width / 2) * .8, 5, color);  //b_right
		break;
	case 5:
		RotateCircle(R_C - (height / 2) * .8, C_C - (width / 2) * .8, 5, color);   // t_left	
		RotateCircle(R_C - (height / 2) * .8, C_C + (width / 2) * .8, 5, color);   //t_right
		RotateCircle(R_C + (height / 2) * .8, C_C - (width / 2) * .8, 5, color);  //b_left
		RotateCircle(R_C + (height / 2) * .8, C_C + (width / 2) * .8, 5, color);  //b_right
		RotateCircle(R_C, C_C, 5, color);
		break;
	case 6:
		RotateCircle(R_C, C_C + (width / 2) * .8, 5, color);
		RotateCircle(R_C, C_C - (width / 2) * .8, 5, color);
	case 4:
		RotateCircle(R_C - (height / 2) * .8, C_C - (width / 2) * .8, 5, color);   // t_left	
		RotateCircle(R_C - (height / 2) * .8, C_C + (width / 2) * .8, 5, color);   //t_right
		RotateCircle(R_C + (height / 2) * .8, C_C - (width / 2) * .8, 5, color);  //b_left
		RotateCircle(R_C + (height / 2) * .8, C_C + (width / 2) * .8, 5, color);  //b_right
		break;

	default:
		break;
	}

	//	RotateCircle(R_C , C_C , 5, z_Angle, y_Angle);                               // 1
	//	RotateCircle(R_C - (height / 2)*.8, C_C + (width / 2).8, 5, z_Angle, y_Angle);   //t_right
}
void PrintBoxNormal(int r_c, int c_c, int Size, int fillcolor = 0, int BoundryColor = 15)
{
	int A[10] = { c_c - Size, r_c - Size, c_c + Size, r_c - Size,
		c_c + Size, r_c + Size, c_c - Size, r_c + Size,
		c_c - Size, r_c - Size
	};
	setcolor(BoundryColor);
	drawpoly(5, A);
	if (fillcolor != -1)
	{
		setfillstyle(SOLID_FILL, fillcolor);
		fillpoly(5, A);
	}
}
void Grid::HighLightBox(int Box_number) {}
void Grid::HighLightBox(int Box_number, int Home_number) {}
int Grid::ColAt(int Angle, int Box_N)
{

	return ((col_center + (2 * m_Box_Size * (Box_N)*cos(Angle * 3.1415926535 / 180))));
}
int Grid::RowAt(int Angle, int Box_N)
{
	return ((row_center + (2 * m_Box_Size * (Box_N)*sin(Angle * 3.1415926535 / 180))));
}
/*void Grid::PrintBox(int Box_number , int FillColor , int BoundryColor)
{
	//int mul = 0;
	//if (Box_number<7 )
	//{
	//	PrintBoxNormal(row_center-2*m_Box_Size, ColAt(0, Box_number + Box_S - 1), m_Box_Size, FillColor, BoundryColor);
	//}
	//else if (Box_number < 14 &&Box_number!=7)
	//{
	//	NumtoRow(Box_number);
	//	PrintBoxNormal(row_center + 2 * m_Box_Size, ColAt(0 ,Box_number+Box_S - 1), m_Box_Size, FillColor, BoundryColor);
	//}
	//else if (Box_number < 19|| Box_number==7)
	//{
	//	NumtoRow(Box_number);
	//	PrintBoxNormal(row_center, ColAt(0, Box_number + Box_S - 1), m_Box_Size, FillColor, BoundryColor);
	//}
	int ri = row_center, ci = col_center;
	GetBoxCenter(Box_number, ri, ci);
	PrintBoxNormal(ri, ci, m_Box_Size, FillColor, BoundryColor);

//	else
//	PrintBoxNormal(row_center, ColAt(180, m_Box_Size, -Box_number +Box_S-1), m_Box_Size, FillColor, BoundryColor);
	//else
	//PrintBoxNormal(row_center, ColAt(180, m_Box_Size, Box_number + mul*(Box_S)), m_Box_Size, FillColor, BoundryColor);
	//PrintBoxNormal(row_center-2*m_Box_Size, ColAt(0, m_Box_Size, Box_number + mul*(Box_S )), m_Box_Size, FillColor, BoundryColor);
	//PrintBoxNormal(row_center + 2 * m_Box_Size, ColAt(0, m_Box_Size, Box_number + mul*(Box_S )), m_Box_Size, FillColor, BoundryColor);
}*/
void Grid::PrintBox(int Box_number, int Home_Number, int FillColor, int Boundry)
{
	int ri = row_center, ci = col_center;
	GetBoxCenter(Box_number, Home_Number, ri, ci);
	PrintBoxNormal(ri, ci, m_Box_Size, FillColor, Boundry);

}
void Grid::Redraw(int Box_number)
{
	int Bn;
	int Hn;
	if (Box_number <= (NumberOfHmes * 13)) {
		Bn = (Box_number % 13) ? Box_number % 13 : 13;
		Hn = Box_number / 13 + 1 - (Box_number % 13 == 0);
	}
	else
	{
		Box_number -= (13 * NumberOfHmes);
		Bn = (Box_number % 5) ? (Box_number % 5) : 5;
		Hn = Box_number / 5 + 1 - (Box_number % 5 == 0);
		Bn += 13;
	}
	int Fllclr = HomeColors[(Hn - 1) * 3 + 2];
	if (Bn == 4 || Bn == 9 || Bn > 13)Fllclr = HomeColors[(Hn - 1) * 3];
	PrintBox(Bn, Hn, Fllclr, B_B_C);

}
void Grid::PrintAllHomeBoxes(int Home_Number, int Fillcolor, int Boundry_color, int Middle_rowcolor)
{
	//	int ci = 0, ri = 0;
//	PrintFourHome(Home_Number);
	if (Fillcolor == -1)Fillcolor = HomeColors[(Home_Number - 1) * 3 + 2];
	if (Middle_rowcolor == -1)Middle_rowcolor = HomeColors[(Home_Number - 1) * 3];
	/*if (Boundry_color == -1)*/ Boundry_color = B_B_C;
	for (int Bi = 1; Bi < 19; Bi++)
	{
		if (Bi != 9 && Bi < 14 && Bi != 4)
			PrintBox(Bi, Home_Number, Fillcolor, Boundry_color);
		else if (Middle_rowcolor != -1)
			PrintBox(Bi, Home_Number, Middle_rowcolor, Boundry_color);
	}

}
namespace MyClass
{
	void FourCilcles(int r_c, int c_c, int d, int r, int Fill_color = 0, int Boundry = 0)
	{
		setfillstyle(SOLID_FILL, Fill_color);
		setcolor(Boundry);
		circle(c_c - d, r_c - d, r);
		circle(c_c - d, r_c + d, r);
		circle(c_c + d, r_c + d, r);
		circle(c_c + d, r_c - d, r);
		floodfill(c_c - d, r_c - d, Boundry);
		floodfill(c_c - d, r_c + d, Boundry);
		floodfill(c_c + d, r_c + d, Boundry);
		floodfill(c_c + d, r_c - d, Boundry);
	}
	void PrintBoxWithDiagal(int r_c, int c_c, int Size, int Fill_color1, int Fill_color2, int Fill_color3, int Fill_color4)
	{

		{    int	A[8] = { c_c - Size, r_c - Size, c_c, r_c,
			c_c - Size, r_c + Size,
			c_c - Size, r_c - Size
		};

		setcolor(Fill_color3);
		setfillstyle(SOLID_FILL, Fill_color3);
		drawpoly(4, A);
		fillpoly(4, A);
		}


		{
			int A[8]{ c_c + Size, r_c - Size, c_c + Size, r_c + Size,
				c_c, r_c,
				c_c + Size, r_c - Size
			};
			setcolor(Fill_color1);
			setfillstyle(SOLID_FILL, Fill_color1);
			fillpoly(4, A);

		}
		{
			int A[8]{ c_c - Size, r_c - Size, c_c + Size, r_c - Size,
				c_c, r_c, c_c - Size, r_c - Size
			};
			setcolor(Fill_color4);
			setfillstyle(SOLID_FILL, Fill_color4);
			fillpoly(4, A);
		}

		{
			int A[8]{ c_c + Size, r_c + Size, c_c - Size, r_c + Size,
				c_c, r_c,
				c_c + Size, r_c + Size
			};
			setcolor(Fill_color2);
			setfillstyle(SOLID_FILL, Fill_color2);
			fillpoly(4, A);
		}
	}
}
void Grid::PrintFourHome(int Home_number)
{
	//	int Right = (Home_number == 2 || Home_number == 3) ? -1 : 1; int Down = (Home_number == 3 || Home_number == 4) ? -1 : 1;
	//	PrintBoxNormal(row_center + Down * 9 * m_Box_Size, col_center + Right * 9 * m_Box_Size, m_Box_Size * 6, HomeColors[(Home_number - 1) * 3 + 0], HomeColors[(Home_number - 1) * 3 + 0]);
	//	PrintBoxNormal(row_center + Down * 9 * m_Box_Size, col_center + Right * 9 * m_Box_Size, m_Box_Size * 4, HomeColors[(Home_number - 1) * 3 + 1], HomeColors[(Home_number - 1) * 3 + 1]);
	//	MyClass::FourCilcles(row_center + Down * 9 * m_Box_Size, col_center + Right * 9 * m_Box_Size , 2 * m_Box_Size, m_Box_Size, HomeColors[(Home_number - 1) * 3 + 2],
	//		HomeColors[(Home_number - 1) * 3 + 2]);

	int H_row_c = 0, H_col_c = 0;
	GetBoxCenterOnHome(0, Home_number, H_row_c, H_col_c);
	PrintBoxNormal(H_row_c, H_col_c, m_Box_Size * 6, HomeColors[(Home_number - 1) * 3 + 0], HomeColors[(Home_number - 1) * 3 + 0]);
	PrintBoxNormal(H_row_c, H_col_c, m_Box_Size * 4, HomeColors[(Home_number - 1) * 3 + 1], HomeColors[(Home_number - 1) * 3 + 1]);
	MyClass::FourCilcles(H_row_c, H_col_c, 2 * m_Box_Size, m_Box_Size, HomeColors[(Home_number - 1) * 3 + 2],
		HomeColors[(Home_number - 1) * 3 + 2]);





}
void Grid::PrintGrid()
{
	//	if (Home_number == 1)

	if (NumberOfHmes == 4)
	{
		MyClass::PrintBoxWithDiagal(row_center, col_center, 3 * m_Box_Size, HomeColors[(0) * 3], HomeColors[(1) * 3], HomeColors[(2) * 3], HomeColors[(3) * 3]); // Arrow
		PrintFourHome(1);
		PrintAllHomeBoxes(1);
		PrintFourHome(2);
		PrintAllHomeBoxes(2);
		PrintFourHome(3);
		PrintAllHomeBoxes(3);
		PrintFourHome(4);
		PrintAllHomeBoxes(4);
	}
}

void Grid::GetBoxCenter(int Box_Number, int& Center_row, int& Center_col)
{
	//     if (Box_Number < 14) GetBoxCenter(Box_Number, 1, Center_row, Center_col);	   
	//else if (Box_Number < 27) { Box_Number -= 13;   GetBoxCenter(Box_Number, 2, Center_row, Center_col); }
	//else if (Box_Number < 40) { Box_Number -= 26;   GetBoxCenter(Box_Number, 3, Center_row, Center_col); }
	//else if (Box_Number < 53) { Box_Number -= 39;   GetBoxCenter(Box_Number, 4, Center_row, Center_col); }
	if (Box_Number <= (NumberOfHmes * 13)) GetBoxCenter((Box_Number - 1) % 13 + 1, ((Box_Number - 1) / 13) + 1, Center_row, Center_col);
	else if (Box_Number <= (NumberOfHmes * 13 + 5)) GetBoxCenter(Box_Number - 13 * NumberOfHmes + 13, 1, Center_row, Center_col);
	else if (Box_Number <= (NumberOfHmes * 13 + 10))GetBoxCenter(Box_Number - 13 * NumberOfHmes + 13 - 5, 2, Center_row, Center_col);
	else if (Box_Number <= (NumberOfHmes * 13 + 15))GetBoxCenter(Box_Number - 13 * NumberOfHmes + 13 - 10, 3, Center_row, Center_col);
	else if (Box_Number <= (NumberOfHmes * 13 + 20))GetBoxCenter(Box_Number - 13 * NumberOfHmes + 13 - 15, 4, Center_row, Center_col);
}
void NumtoRow(int& B_N)
{
	if (B_N < 7) return;
	if (B_N == 7)
	{
		B_N = 6;
		return;
	}
	if (B_N < 14)
	{
		B_N = 14 - B_N;
		return;
	}
	if (B_N < 19)
	{
		B_N = 19 - B_N;
		return;
	}
}
int Grid::HomeRowtoNum(int row, int col)
{
	bool SH = 0;
	if (col >= -1 && col <= 1)
	{
		std::swap(row, col); SH = 1;
	}

	if ((row == -1 && !SH) || (row == 1 && SH))
	{
		if (col >= Box_S)
		{
			if (SH)return col - Box_S + 1 + 13 * (NumberOfHmes / 4);
			return col - Box_S + 1;
		}
		else if (col <= (-1 * Box_S))
		{
			if (SH) return(13 * (3 * NumberOfHmes / 4 + 1) + 2) + col;
			return (13 * (NumberOfHmes / 2 + 1) + 2) + col;
		}

	}
	if ((row == 1 && !SH) || (row == -1 && SH))
	{
		if (col >= Box_S)
		{
			if (SH) return 13 * (NumberOfHmes / 4 + 1) - col + Box_S;
			return 13 - col + Box_S;
		}
		else if (col <= (-1 * Box_S))
		{
			if (SH)return(13 * (3 * NumberOfHmes / 4) - col - (Box_S - 1));
			return(13 * (NumberOfHmes / 2) - col - (Box_S - 1));
		}
	}
	if (row == 0)
	{
		if (col >= Box_S)
		{
			if (col == 7 && !SH) return 7;
			if (col == 7 && SH) return col - Box_S + 2 + 13 * (NumberOfHmes / 4);
			if (SH)return ((NumberOfHmes * 13) + 5 + 5 - col + Box_S);
			return ((NumberOfHmes * 13) + 5 - col + Box_S);
		}
		else if (col <= (-1 * Box_S))
		{
			if (col == -7 && !SH) return (13 * (NumberOfHmes / 2 + 1) + 1) + col;
			if (col == -7 && SH)  return(13 * (3 * NumberOfHmes / 4) - col - (Box_S - 2));
			if (SH) return ((NumberOfHmes * 13) + 20 + col + Box_S);
			return ((NumberOfHmes * 13) + 15 + col + Box_S);

		}

	}
	//if (col==-1)
	//{
	//
	//}
	return -1;
}
void Grid::PrintHomeColor(int R_C, int C_C, int HomeNumber, int Size, bool IsInner, int b)
{
	int c = HomeColors[3 * (HomeNumber - 1) + IsInner];
	setcolor(c);
	setfillstyle(SOLID_FILL, c);
	rectangle(C_C - Size, R_C - Size, C_C + Size, R_C + Size);
	floodfill(C_C, R_C, c);

	//	c = HomeColors[3 * (HomeNumber - 1) + !IsInner];
	//	setcolor(c);
	//	setfillstyle(SOLID_FILL, c);
	//	rectangle(C_C - Size+b, R_C - Size+b, C_C + Size-b, R_C + Size-b);
	//	floodfill(C_C, R_C, c);
}
void Grid::GetBoxCenter(int Box_Number, int Home_number, int& Center_row, int& Center_col)            // Box Number with refrence to any home
{
	if ((NumberOfHmes == 4))
	{
		switch (Home_number)
		{
		case 1:
		{
			if (Box_Number < 7) { Center_row = row_center - 2 * m_Box_Size; }
			else if (Box_Number < 14 && Box_Number != 7) { Center_row = row_center + 2 * m_Box_Size; }
			else if (Box_Number < 19 || Box_Number == 7) { Center_row = row_center; }
			NumtoRow(Box_Number);  Center_col = ColAt(0, Box_Number + Box_S - 1);

			break;
		}
		case 2:
		{
			Center_col = col_center;
			if (Box_Number < 7) Center_col += (2 * m_Box_Size);
			else if (Box_Number < 14 && Box_Number != 7)Center_col -= (2 * m_Box_Size);
			NumtoRow(Box_Number);
			Center_row = RowAt(90, Box_Number + 1);
			break;
		}
		case 3:
		{
			if (Box_Number < 7) { Center_row = row_center + 2 * m_Box_Size; }
			else if (Box_Number < 14 && Box_Number != 7) { Center_row = row_center - 2 * m_Box_Size; }
			else if (Box_Number < 19 || Box_Number == 7) { Center_row = row_center; }
			NumtoRow(Box_Number);  Center_col = ColAt(180, Box_Number + Box_S - 1);
			break;
		}
		case 4:
		{
			Center_col = col_center;
			if (Box_Number < 7) Center_col -= (2 * m_Box_Size);
			else if (Box_Number < 14 && Box_Number != 7)Center_col += (2 * m_Box_Size);
			NumtoRow(Box_Number);
			Center_row = RowAt(-90, Box_Number + 1);
			break;
		}
		default:
			break;
		}

	}

}
void Grid::GetBoxCenterOnHome(int Box_Number, int Home_number, int& Center_row, int& Center_col)
{
	if (NumberOfHmes == 4)
	{
		if (Box_Number >= 0)
		{
			int Right = (Home_number == 2 || Home_number == 3) ? -1 : 1; int Down = (Home_number == 3 || Home_number == 4) ? -1 : 1;
			Center_row = row_center + Down * 9 * m_Box_Size;
			Center_col = col_center + Right * 9 * m_Box_Size;
		}
		if (Box_Number == 1) Center_col += 2 * m_Box_Size;
		else if (Box_Number == 2) Center_row += 2 * m_Box_Size;
		else if (Box_Number == 3) Center_col -= 2 * m_Box_Size;
		else if (Box_Number == 4) Center_row -= 2 * m_Box_Size;
	}
	//PrintFourHome()
}
int Grid::GetSize()
{
	return m_Box_Size;
}
bool Grid::IsBox(int row, int col)
{
	if (NumberOfHmes == 4)
	{

		int Rs = 3 * m_Box_Size + row_center, Re = 15 * m_Box_Size + row_center;
		int Cs = -3 * m_Box_Size + col_center, Ce = 3 * m_Box_Size + col_center;
		if ((col >= (Cs) && col <= Ce) && (row >= (Rs) && row <= (Re) || (row <= row_center - 3 * m_Box_Size && row >= (row_center - (15 * m_Box_Size)))))
		{
			return true;
		}
		Rs = row_center - 3 * m_Box_Size, Re = row_center + 3 * m_Box_Size;
		Cs = col_center - 15 * m_Box_Size; Ce = col_center + 15 * m_Box_Size;
		if ((row >= Rs && row <= Re) && ((col >= Cs && col <= (col_center - 3 * m_Box_Size)) || (col >= (col_center + 3 * m_Box_Size) && col <= Ce)))
		{
			return true;
		}
	}
	return 0;
}
bool Grid::IsCenterBox(int row, int col)
{
	if (NumberOfHmes == 4)
	{
		if (row <= (row_center + m_Box_Size * 3) && row >= (row_center - m_Box_Size * 3) &&
			col <= (col_center + m_Box_Size * 3) && col >= (col_center - m_Box_Size * 3)
			)
			return true;
	}
	return false;
}
int Grid::Box_Row(int Angle, int row)
{

	row = (row - row_center) / sin(Angle * 3.1415926535 / 180);
	//	else row = (row + row_center) / sin(Angle*3.1415926535 / 180);
	if (row < m_Box_Size && row >(-1 * m_Box_Size)) return 0;
	row = (row > 0) ? (row - m_Box_Size) : (row + m_Box_Size);
	if (row > 0)
		return (row / (2 * m_Box_Size)) + 1;
	return (row / (2 * m_Box_Size)) - 1;
}
int Grid::Box_Col(int Angle, int col)
{
	col = (col - col_center) / cos(Angle * 3.1415926535 / 180);
	if (col < m_Box_Size && col >(-1 * m_Box_Size)) return 0;
	col = (col > 0) ? (col - m_Box_Size) : (col + m_Box_Size);
	if (col > 0)
		return (col / (2 * m_Box_Size)) + 1;
	return (col / (2 * m_Box_Size)) - 1;
}

int Grid::BoxNumber(int row, int col)
{
	if (NumberOfHmes == 4)
	{
		return HomeRowtoNum(Box_Row(90, row), Box_Col(0, col));
	}
	return 0;
}


Grid::~Grid()
{
}
