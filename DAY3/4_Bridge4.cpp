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

class PointImpl; // 핵심 : 전방선언만 있으면 포인터 변수는 선언가능
				// 즉, 추상층의 헤더에서 구현층의 헤더를
				// 포함할 필요 없음.
class Point
{
	// 구현층을 가리키는 포인터
	PointImpl* impl; 
public:
	Point();
	void print();
};

// Point.cpp
#include "PointImpl.h" // 여기서는 헤더 필요
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




// 위 코드가 C++ IDioms 인 "PIMPL(Pointer to IMPlementation)" 이라는 기술
// => 컴파일 시간 방화벽
// => 코드(헤더)의 변화가 생길때 다른 소스도 다시 컴파일되는 것을 막는것

// 장점 1. 컴파일 시간 빨라지고
// 장점 2. 완벽한 정보은닉, 최종사용자에게 구현의 헤더를 제공할 필요 없다.
//		   추상층의 헤더만 전달하면 된다.
