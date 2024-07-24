class PointImpl
{
	int x, y;
	int debug;
public:
	void print();
};

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"

Point::Point() { impl = new PointImpl(); }
void Point::print() { impl->print(); } // 구현 생략

// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


