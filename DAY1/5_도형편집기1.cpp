// 15page ~ 
#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 "객체지향"으로 만들어 봅시다.
// #1. 모든 도형을 타입화
// #2. 모든 도형은 공통의 특징이 있다.

class Shape {
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape {
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape {
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	//std::vector <Rect *> v;
	std::vector <Shape *> v;
}

