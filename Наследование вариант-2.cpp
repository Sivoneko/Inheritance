// Наслдедование-Вариант 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include <conio.h>
#include <string>
using namespace std;

void Menu();
void Menu_Point();
void Menu_Colored_Point();
void Menu_Line();
void Menu_Colored_Line();
void Menu_Poly();

Point New_Coord();

int Change_Number();

string Change_Color();

void Output_Points(CLine*);

int main()
{
	/*
	CcoloredPoint first(2);
	string color;
	Point point;
	for (int i(0); i < 2; i++)
	{
	cout << "Ccolored point: " << i << ": " << endl;
	cout << "Enter color: ";
	cin.get();
	getline(cin, color);
	cout << "Enter X: ";
	cin >> point.x;
	cout << "Enter Y: ";
	cin >> point.y;

	first.SetColor(point, color, i);
	}
	cout << first;

	CLine second(2);
	*/

	/*
	CLine first(2);
	Point point1, point2;

	for (int i(0); i < 2; i++)
	{
	cout << "Point 1:" << endl;
	cout << "Enter X: ";
	cin >> point1.x;
	cout << "Enter Y: ";
	cin >> point1.y;
	cout << "Point 2:" << endl;
	cout << "Enter X: ";
	cin >> point2.x;
	cout << "Enter Y: ";
	cin >> point2.y;

	first.SetLine(point1, point2, i);
	}

	cout << first.GetLine()[0] << endl;
	cout << first.GetLine()[1] << endl;
	*/

	/*
	CColoredLine first;

	cin >> first;

	cout << first;

	first.SetColorForLine("Black", 1);

	cout << first;

	for (int i(0); i < first.GetNumberofPoint(); i++)
	{
	cout << first.GetPointofColoreLine()[i];
	}
	*/


	CPoint point;
	CcoloredPoint Cpoint;
	CLine line;
	CColoredLine Cline;
	CPolyLine poly;

	
	CPoint* p,*Cp;
	p = &point;
	Cp = &Cpoint;

	
	CLine* L, *P, *CL;
	L = &line;
	P = &poly;
	CL = &Cline;
	
	
	char answer;
	do
	{
		system("cls");
		Menu();

		cout << "Enter answer: ";
		cin >> answer;

		switch (answer)
		{
		case '1':
		{
			system("cls");
			Menu_Point();

			do
			{
				cout << "Enter answer:";
				cin >> answer;
				switch (answer)
				{
				case '1':
				{
					cin >> *p;
					break;
				}
				case '2':
				{
					try
					{
						p->SetPoint(New_Coord(), Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '3':
				{
					try
					{
						cout << *p << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '4':
				{
					try
					{
						cout << p->GetCoordPoint(Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				default:
					break;
				}

			} while (answer != '5');
			break;

		}
		case '2':
		{
			system("cls");
			Menu_Colored_Point();
			do
			{
				cout << "Enter answer:";
				cin >> answer;

				switch (answer)
				{
				case '1':
				{
					cin >> Cpoint;
					break;
				}
				case '2':
				{
					try
					{
						Cp->SetPoint(New_Coord(), Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '3':
				{
					try
					{
						Cpoint.SetColor(Change_Color(), Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '4':
				{
					try
					{
						cout << Cpoint << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '5':
				{
					try
					{
						cout << "Color: " << Cpoint.GetColor(Change_Number()) << 
							                 Cpoint.GetCoordPoint(Change_Number()) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '6':
				{
					try
					{
						cout << Cp->GetCoordPoint(Change_Number()) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '7':
				{
					try
					{
						cout << "Color: " << Cpoint.GetColor(Change_Number()) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				default:
					break;
				}


			} while (answer != '8');

			break;
		}
		case '3':
		{
			system("cls");
			Menu_Line();
			do
			{
				cout << "Enter answer:";
				cin >> answer;
				switch (answer)
				{
				case '1':
				{
					cin >> line;

					break;
				}
				case '2':
				{
					try
					{
						L->SetLine(New_Coord(), New_Coord(), Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '3':
				{
					try
					{
						cout << line << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '4':
				{
					try
					{
						cout << L->GetCoordLine(Change_Number()) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '5':
				{
					try
					{
						Output_Points(L);
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
				
					break;

				}
				default:
					break;
				}
			} while (answer != '6');

			break;
		}
		case '4':
		{
			system("cls");
			Menu_Colored_Line();
			do
			{
				cout << "Enter answer:";
				cin >> answer;
				switch (answer)
				{
				case '1':
				{
					cin >> Cline;
					break;
				}
				case '2':
				{
					try
					{
						CL->SetLine(New_Coord(), New_Coord(), Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '3':
				{
					try
					{
						Cline.SetColor(Change_Color(), Change_Number());
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '4':
				{
					try
					{
						cout << Cline << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '5':
				{
					int n = Change_Number();
					try
					{
						cout << "Color: " << Cline.GetColor(n) << CL->GetCoordLine(n) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '6':
				{
					try
					{
						cout << CL->GetCoordLine(Change_Number()) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '7':
				{
					try
					{
						cout << "Color: " << Cline.GetColor(Change_Number()) << endl;
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				case '8':
				{
					try
					{
						Output_Points(CL);
					}
					catch (char* a)
					{
						cout << a << endl;
					}
					
					break;
				}
				default:
					break;
				}
			} while (answer != '9');

			break;
		}
		case '5':
		{
			system("cls");
			Menu_Poly();
			do
			{
				cout << "Enter answer:";
				cin >> answer;

				switch (answer)
				{
				case '1':
				{
					cin >> poly;
					break;
				}
				case '2':
				{
					P->SetLine(New_Coord(), New_Coord(), Change_Number());
					break;
				}
				case '3':
				{
					cout << poly << endl;
					break;
				}
				case '4':
				{
					P->GetCoordLine(Change_Number());
					break;
				}
				case '5':
				{
					Output_Points(P);
					break;
				}
				default:
					break;
				}

			} while (answer != '6');

			break;
		}
		default:
			break;
		}
	} while (answer != 'o');

	_getch();
	return 0;
	
}

void Menu()
{
	cout << "***** MENU ***** \n";
	cout << "1 - Work with usual Points \n";
	cout << "2 - Work with Colored Points \n";
	cout << "3 - Work with Line \n";
	cout << "4 - Work with Colored Line \n ";
	cout << "5 - Work with Poly \n";
}
void Menu_Point()
{
	cout << "1 - Set Point: \n";
	cout << "2 - Change Coord: \n";
	cout << "3 - Get coord of all Points: \n";
	cout << "4 - Get coord of one Point: \n";
	cout << "5 - Out \n";
}
void Menu_Colored_Point()
{
	cout << "1 - Set Point: \n";
	cout << "2 - Change Coord: \n";
	cout << "3 - Change color: \n";
	cout << "4 - Get coord and color of all Points: \n";
	cout << "5 - Get coord and color  of one Point: \n";
	cout << "6 - Get only coord of Point: \n";
	cout << "7 - Get only color of Point: \n";
	cout << "8 - Out \n";
}
void Menu_Line()
{
	cout << "1 - Set Line: \n";
	cout << "2  -Change Line's Coord: \n";
	cout << "3 - Get coord of all Lines: \n";
	cout << "4 - Get coord of one Line: \n";
	cout << "5 - Get coord of Line's Points: \n";
	cout << "6 - Out \n";
}
void Menu_Colored_Line()
{
	cout << "1 - Set Line: \n";
	cout << "2 - Change Coord: \n";
	cout << "3 - Change color: \n";
	cout << "4 - Get coord and color of all Lines: \n";
	cout << "5 - Get coord and color  of one Line: \n";
	cout << "6 - Get only coord of Line: \n";
	cout << "7 - Get only color of Line: \n";
	cout << "8 - Get coord of Line's Points: \n";
	cout << "9 - Out \n";
}
void Menu_Poly()
{
	cout << "1 - Set Line: \n";
	cout << "2 - Change Coord of Line: \n";
	cout << "3 - Get coord of Poly: \n";
	cout << "4 - Get coord of one Poly's Line: \n";
	cout << "5 - Get coord of Poly's Line's Points: \n";
	cout << "6 - Out \n";
}

Point New_Coord()
{
	Point point;

	cout << "Enter new coords: ";

	cout << "Enter X: ";
	cin >> point.x;
	cout << "Enter Y: ";
	cin >> point.y;

	return point;
}

int Change_Number()
{
	int Number;
	cout << "Enter number of point you want change / output: ";
	cin >> Number;

	return Number;
}

string Change_Color()
{
	string color;
	cout << "Enter color: ";
	cin.get();
	getline(cin, color);

	return color;
}

void Output_Points(CLine* L)
{
	int Count = 0;
	for (int i(0); i < L->GetNumberLine(); i++)
	{
		cout << "Line " << i << ": " << endl;

		for (int j(0); j < 2; j++)
		{
			cout << "Point " << j << ": " << L->GetCoordPoint(Count);
			Count++;
		}

	}
}