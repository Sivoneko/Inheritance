#pragma once
#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Point
{
	int x;
	int y;

	friend ostream& operator<<(ostream&, Point);
};

class CPoint
{
protected:
	Point * Coordinates;
	int n;// количество элементов (в нашем случае - точек)
public:
	CPoint();
	CPoint(Point*, int);
	CPoint(int);
	CPoint(CPoint&);

	virtual void SetPoint(Point, int);
	virtual Point GetCoordPoint(int i);

	friend istream& operator>>(istream&, CPoint&);
	friend ostream& operator<<(ostream&, CPoint);

	virtual ~CPoint();
};

class CcoloredPoint : virtual public CPoint
{
protected:
	string * color;
public:
	CcoloredPoint();
	CcoloredPoint(Point*, int);
	CcoloredPoint(int);
	CcoloredPoint(CcoloredPoint&);

	void SetColor(string, int);
	virtual void SetPoint(Point, int);
	string GetColor(int);
	virtual Point GetCoordPoint(int);

	friend istream& operator>>(istream&, CcoloredPoint&);
	friend ostream& operator<<(ostream&, CcoloredPoint);

	virtual ~CcoloredPoint();
};

class CLine : public CPoint
{
protected:
	Point * line;
	int nLine;
public:
	CLine();
	CLine(Point*, int);
	CLine(int);

	virtual void SetLine(Point, Point, int);
	virtual Point GetCoordLine(int);
	virtual Point GetCoordPoint(int);
	virtual int GetNumberPoint();
	virtual int GetNumberLine();

	friend istream& operator>>(istream&, CLine&);
	friend ostream& operator<<(ostream&, CLine);

	virtual ~CLine();
};

class CColoredLine : public CLine
{
protected:
	string * color;
public:
	CColoredLine();
	CColoredLine(Point*, int);
	CColoredLine(int);

	void SetColor(string, int);
	virtual void SetLine(Point, Point, int);
	virtual string GetColor(int);
	virtual Point GetCoordLine(int);
	virtual Point GetCoordPoint(int);
	virtual int GetNumberPoint();

	friend istream& operator>>(istream&, CColoredLine&);
	friend ostream& operator<<(ostream&, CColoredLine);

	virtual ~CColoredLine();
};

class CPolyLine : public CLine
{
public:
	CPolyLine();
	CPolyLine(Point*, int);
	CPolyLine(int);

	virtual void SetLine(Point, Point, int);
	virtual Point GetCoordPoint(int);
	virtual Point GetCoordLine(int);
	virtual int GetNumberPoint();

	friend istream& operator>>(istream&, CPolyLine&);
	friend ostream& operator<<(ostream&, CPolyLine);

	virtual ~CPolyLine();

};
