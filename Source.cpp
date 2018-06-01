#include "stdafx.h"
#include "Header.h"


//------------------------------------------------------------------
// struct Point
ostream& operator<<(ostream& os, Point vivod)
{
	os << "X: " << vivod.x << " Y: " << vivod.y << endl;
	return os;
}

//------------------------------------------------------------------
// class CPoint

CPoint::CPoint() { Coordinates = NULL; n = 0; }
CPoint::CPoint(Point* xy, int size)
{
	xy = new Point[size];
	n = size;
	for (int i(0); i < size; i++)
	{
		Coordinates[i] = xy[i];
	}
}
CPoint::CPoint(int size)
{
	n = size;
	Coordinates = new Point[size];
}
CPoint::CPoint(CPoint& M)
{
	Coordinates = new Point[M.n];
	n = M.n;
	for (int i(0); i < M.n; i++)
	{
		Coordinates[i] = M.Coordinates[i];
	}
}

void CPoint::SetPoint(Point point, int i)
{
	if (Coordinates == NULL)
		throw "You didn't set memory!";
	Coordinates[i].x = point.x;
	Coordinates[i].y = point.y;
}
Point CPoint::GetCoordPoint(int i)
{
	if (Coordinates == NULL)
		throw "There is no Coordinates!";
	return Coordinates[i];
}

istream& operator>>(istream& is, CPoint& point)
{
	cout << "Enter number of points: ";
	is >> point.n;
	point.Coordinates = new Point[point.n];
	for (int i(0); i < point.n; i++)
	{
		cout << "Enter x: ";
		is >> point.Coordinates[i].x;
		cout << "Enter y: ";
		is >> point.Coordinates[i].y;
	}
	return is;
}
ostream& operator<<(ostream& os, CPoint point)
{
	if (point.Coordinates == NULL)
		throw "There is nothing to output!";
	for (int i(0); i < point.n; i++)
	{
		os << "X: " << point.Coordinates[i].x << " Y: " << point.Coordinates[i].y << endl;
	}
	return os;
}

CPoint::~CPoint()
{
	if (!Coordinates)
	{
		delete[] Coordinates;
		cout << "Destructor of Point" << endl;
	}
}

//------------------------------------------------------------------
// class CcoloredPoint
CcoloredPoint::CcoloredPoint() : CPoint() { color = NULL; }
CcoloredPoint::CcoloredPoint(Point* xy, int size) : CPoint(xy, size) { color = new string[size]; };
CcoloredPoint::CcoloredPoint(int size) :CPoint(size) { color = new string[size]; }
CcoloredPoint::CcoloredPoint(CcoloredPoint& M)
{
	color = M.color;
	CPoint::CPoint(M);
}

void CcoloredPoint::SetColor(string Color, int i)
{
	if (color == NULL)
		throw "You don't have memory for color!";
	color[i] = Color;
}
void CcoloredPoint::SetPoint(Point point, int i)
{
	CPoint::SetPoint(point, i);
}
string CcoloredPoint::GetColor(int i)
{
	if (color == NULL)
		throw "You don't have memory for color!";
	return color[i];
}
Point CcoloredPoint::GetCoordPoint(int i)
{
	return CPoint::Coordinates[i];
}



istream& operator>>(istream& is, CcoloredPoint& Cpoint)
{
	cout << "Enter number of points: ";
	is >> Cpoint.n;
	Cpoint.color = new string[Cpoint.n];
	Cpoint.Coordinates = new Point[Cpoint.n];
	for (int i(0); i < Cpoint.n; i++)
	{
		cin.get();
		cout << "Enter color: ";
		getline(is, Cpoint.color[i]);

		cout << "Enter x: ";
		is >> Cpoint.Coordinates[i].x;
		cout << "Enter y:";
		is >> Cpoint.Coordinates[i].y;
	}
	return is;
}
ostream& operator<<(ostream& os, CcoloredPoint Cpoint)
{
	if (Cpoint.Coordinates == NULL)
		throw "There is nothing to output";
	for (int i(0); i < Cpoint.n; i++)
	{
		cout << "Color: " << Cpoint.color[i] << " X: " << Cpoint.Coordinates[i].x << " Y: " << Cpoint.Coordinates[i].y << endl;
	}
	return os;
}

CcoloredPoint::~CcoloredPoint()
{
	delete[] color;
	cout << "Destructor of CCPoint" << endl;
}


//------------------------------------------------------------------
// class CLine
CLine::CLine() :CPoint() { line = NULL; nLine = 0; }
CLine::CLine(Point* xy, int size) :CPoint(xy, size * 2) { nLine = size; line = new Point[size]; }
CLine::CLine(int size) : CPoint(size * 2) { nLine = size; line = new Point[size]; }


void CLine::SetLine(Point point1, Point point2, int i)
{
	if (line == NULL)
		throw "You don't have memory for line!";

	if (i == 0)
	{
		CPoint::SetPoint(point1, i);
		CPoint::SetPoint(point2, i + 1);

		line[i].x = CPoint::Coordinates[i + 1].x - CPoint::Coordinates[i].x;
		line[i].y = CPoint::Coordinates[i + 1].y - CPoint::Coordinates[i].y;
	}
	else
	{
		CPoint::SetPoint(point1, i + 1);
		CPoint::SetPoint(point2, i + 2);

		line[i].x = CPoint::Coordinates[i + 2].x - CPoint::Coordinates[i + 1].x;
		line[i].y = CPoint::Coordinates[i + 2].y - CPoint::Coordinates[i + 1].y;
	}

	//[i].x = point2.x - point1.x;
	//line[i].y = point2.y - point1.y;
}

Point CLine::GetCoordLine(int i)
{
	if (line == NULL)
		throw "You don't have memory for line!";
	return line[i];
}

Point CLine::GetCoordPoint(int i)
{
	return CLine::Coordinates[i];
}

int CLine::GetNumberPoint()
{
	return CPoint::n;
}

int CLine::GetNumberLine()
{
	return CLine::nLine;
}


istream& operator>>(istream& is, CLine& Cline)
{
	cout << "Enter number of lines: ";
	is >> Cline.nLine;
	Cline.line = new Point[Cline.nLine];
	Cline.Coordinates = new Point[Cline.nLine * 2];
	Cline.n = Cline.nLine * 2;


	int Count = 0;

	for (int i(0); i < Cline.nLine; i++)
	{
		cout << "Enter points for line " << i << ": " << endl;
		for (int j(0); j < 2; j++)
		{
			cout << "Point " << j << ": " << endl;
			cout << "Enter X: ";
			is >> Cline.Coordinates[Count].x;
			cout << "Enter Y: ";
			is >> Cline.Coordinates[Count].y;
			Count++;
		}
		Cline.line[i].x = Cline.Coordinates[Count - 1].x - Cline.Coordinates[Count - 2].x;
		Cline.line[i].y = Cline.Coordinates[Count - 1].y - Cline.Coordinates[Count - 2].y;
	}
	return is;
}

ostream& operator<<(ostream& os, CLine Cline)
{
	if (Cline.line == NULL)
		throw "There is nothing to output";

	for (int i(0); i < Cline.nLine; i++)
	{
		cout << "Line " << i << ":" << endl;
		os << "X: " << Cline.line[i].x << " Y: " << Cline.line[i].y << endl;
	}
	return os;
}

CLine::~CLine()
{
	delete[] line;
	if (CLine::Coordinates != NULL)
	{
		delete[] CLine::Coordinates;
	}
	cout << "Destructor of Line" << endl;
}


//------------------------------------------------------------------
// class CColoredLine

CColoredLine::CColoredLine() :CLine() { color = NULL; }
CColoredLine::CColoredLine(Point* xy, int size) : CLine(xy, size) { color = new string[size]; }
CColoredLine::CColoredLine(int size) : CLine(size) { color = new string[size]; }

void CColoredLine::SetColor(string Color, int i)
{
	if (color == NULL)
		throw "You don't have memory for color!";
	color[i] = Color;
}
 void CColoredLine::SetLine(Point point1, Point point2, int i)
{
	CLine::SetLine(point1, point2, i);
}
 string CColoredLine::GetColor(int i)
{
	if (color == NULL)
		throw "You don't have memory for color!";
	return color[i];
}
 Point CColoredLine::GetCoordLine(int i)
{

	return CLine::GetCoordLine(i);
}
 Point CColoredLine::GetCoordPoint(int i)
{
	return CPoint::Coordinates[i];
}
int CColoredLine::GetNumberPoint()
{
	return CColoredLine::n;
}

istream& operator>>(istream& is, CColoredLine& CCline)
{
	cout << "Enter number of lines: ";
	is >> CCline.nLine;

	CCline.line = new Point[CCline.nLine];
	CCline.Coordinates = new Point[CCline.nLine * 2];
	CCline.color = new string[CCline.nLine];
	CCline.n = CCline.nLine * 2;


	int Count = 0;

	for (int i(0); i < CCline.nLine; i++)
	{
		cout << "Enter color: ";
		cin.get();
		getline(is, CCline.color[i]);

		cout << "Enter points for line " << i << ": " << endl;
		for (int j(0); j < 2; j++)
		{
			cout << "Point " << j << ": " << endl;
			cout << "Enter X: ";
			is >> CCline.Coordinates[Count].x;
			cout << "Enter Y: ";
			is >> CCline.Coordinates[Count].y;
			Count++;
		}
		CCline.line[i].x = CCline.Coordinates[Count - 1].x - CCline.Coordinates[Count - 2].x;
		CCline.line[i].y = CCline.Coordinates[Count - 1].y - CCline.Coordinates[Count - 2].y;
	}
	return is;
}
ostream& operator<<(ostream& os, CColoredLine CCline)
{
	if (CCline.line == NULL)
		throw "Nothing to output";

	for (int i(0); i < CCline.nLine; i++)
	{
		cout << "Colored Line " << i << ":" << endl;
		os << "Color: " << CCline.color[i] << " X: " << CCline.Coordinates[i].x << " Y: " << CCline.Coordinates[i].y << endl;
	}
	return os;
}

CColoredLine::~CColoredLine()
{
	delete[] color;
	cout << "Destructor of CCline" << endl;
}


//------------------------------------------------------------------
// class CPolyLine

CPolyLine::CPolyLine() :CLine() {};
CPolyLine::CPolyLine(Point* xy, int size) : CLine(xy, size) { }
CPolyLine::CPolyLine(int size) : CLine(size) {}

void CPolyLine::SetLine(Point point1, Point point2, int i)
{
	CLine::SetLine(point1, point2, i);
}
Point CPolyLine::GetCoordPoint(int i)
{
	return CPoint::Coordinates[i];
}
Point CPolyLine::GetCoordLine(int i)
{
	return CLine::GetCoordLine(i);
}
int CPolyLine::GetNumberPoint()
{
	return CPolyLine::n;
}

istream& operator>>(istream& is, CPolyLine& Cpolyline)
{
	cout << "Enter number op Poly's side: ";
	is >> Cpolyline.nLine;
	Cpolyline.n = Cpolyline.nLine * 2;

	Cpolyline.line = new Point[Cpolyline.nLine];
	Cpolyline.Coordinates = new Point[Cpolyline.n];

	int Count = 0;

	for (int i(0); i < Cpolyline.nLine; i++)
	{
		if ((Cpolyline.nLine - 1) > 2)
		{
			cout << "Enter points for line " << i << ": " << endl;
		}
		if (i == 0)
		{
			for (int j(0); j < 2; j++)
			{
				cout << "Point " << Count << ": " << endl;
				cout << "Enter X: ";
				is >> Cpolyline.Coordinates[Count].x;
				cout << "Enter Y: ";
				is >> Cpolyline.Coordinates[Count].y;
				Count++;
			}
		}
		else
		{
			Cpolyline.Coordinates[Count].x = Cpolyline.Coordinates[Count - 1].x;
			Cpolyline.Coordinates[Count].y = Cpolyline.Coordinates[Count - 1].y;

			if ((Cpolyline.nLine - i) != 1)
			{
				cout << "Point " << Count << ": " << endl;
				cout << "Enter X: ";
				is >> Cpolyline.Coordinates[Count + 1].x;
				cout << "Enter Y: ";
				is >> Cpolyline.Coordinates[Count + 1].y;
				Count += 2;
			}
			else
			{
				Cpolyline.Coordinates[Count + 1].x = Cpolyline.Coordinates[0].x;
				Cpolyline.Coordinates[Count + 1].y = Cpolyline.Coordinates[0].y;

			}
		}

		Cpolyline.line[i].x = Cpolyline.Coordinates[Count - 1].x - Cpolyline.Coordinates[Count - 2].x;
		Cpolyline.line[i].y = Cpolyline.Coordinates[Count - 1].y - Cpolyline.Coordinates[Count - 2].y;
	}
	return is;
}
ostream& operator<<(ostream& os, CPolyLine Cpolyline)
{
	for (int i(0); i < Cpolyline.nLine; i++)
	{
		os << "X: " << Cpolyline.line[i].x << " Y: " << Cpolyline.line[i].y << endl;
	}
	return os;
}

CPolyLine::~CPolyLine()
{
	cout << "Destructor of Poly" << endl;
}