// 실제 구현층
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug;

public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 



//=============================================
// 추상층(중간층)
// Point.h
class Point
{
	// 구현층을 가리키는 포인터
	PointImpl* impl; 
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


