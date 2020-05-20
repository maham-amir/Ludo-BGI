#pragma once
class Grid
{
public:
	int m_Box_Size;     // size of square 
					   // size imeasured from center of box to any side or vertex
	int row_center;    // Center of overall screen  
	int col_center;	   // Center of overall screen
	int NumberOfHmes;  // decided by number of players or from constructor type

	int Shift;        // sometimes error occure in the diagonal grids due to approximation  sin() cos() values
					  // it is automatically calculated but sometimes passsed to constructor(not recommended)

	int Box_S;       // internal thing can't be canged by other classes
					// it is not a start location of any home it's just related to printing within this class

	int* HomeColors;       // An array of colors with respect to homeNumber  
	int B_B_C;           // Box_BackGround Colors or boundry line color
	int ColAt(int Angle, int Box_N);
	int RowAt(int Angle, int Box_N);
	int Box_Row(int Angle, int row);
	int Box_Col(int Angle, int row);
	int HomeRowtoNum(int row, int col);
public:
	Grid() {}
	void Dice(int Num, int R_C, int C_C, int Size, int color);
	void HighLightBox(int Box_number);
	void HighLightBox(int Box_number, int Home_number);
	void Redraw(int Box_number);
	//	void PrintBox( int Box_number, int FillColor = -1, int BoundryColor = 15);              //print single box only     // it relates from very first home               
	void PrintBox(int Box_number, int Home_Number, int FillColor = -1, int Boundry = 15);    //print single box only     // it relates from box number of any home within 
	void PrintAllHomeBoxes(int Home_Number, int Fillcolor = -1, int Boundry_color = 15, int Middle_rowcolor = -1);   // Print All Boxes of a home with
	void PrintHomeColor(int R_C, int C_C, int HomeNumber, int Size, bool IsInner, int boundry = 5);																											  // different middle row color if required
	void PrintGrid();          // Print Whole or Grid Full Screen
	void PrintFourHome(int Home_number);
	void GetBoxCenter(int Box_Number, int& Center_row, int& Center_col);
	void GetBoxCenter(int Box_Number, int Home_number, int& Center_row, int& Center_col);            // Box Number with refrence to any home
	void GetBoxCenterOnHome(int Box_Number, int Home_number, int& Center_row, int& Center_col);
	int BoxNumber(int row, int col);

	int GetSize();
	bool IsBox(int row, int col);
	bool IsCenterBox(int row, int col);
	void PrintDiece(int Turn, int value, int Size);
	Grid(int NumberofHomes, int Window_Rows = 1000, int Window_Cols = 1000, int* ColorArray = nullptr, int Boxesdefault_Color = 15);
	~Grid();
};