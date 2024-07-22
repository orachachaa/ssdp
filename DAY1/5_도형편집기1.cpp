// 15page ~ 
#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 "객체지향" 으로 만들어 봅시다.

// #1. 모든 도형을 타입화 하면 편리합니다.
// #2. 모든 도형은 공통의 특징이 있다(색상등..)
//     또한, 기반 클래스가 있다면 모든 도형을 하나의 컨테이너에 묶어서 관리할수 있다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// int x, y, w, h, 생성자등은 생략(있다고 가정)
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 타입의 객체만 보관 가능.
	std::vector<Shape*> v; // 모든 도형을 보관할수 있는 컨테이너!!
}

