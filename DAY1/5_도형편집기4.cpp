// 4.cpp - 2번 복사후 주석제거. 

#include <iostream>
#include <vector>

// 핵심 #1. 모든 파생클래스(도형)의 공통의 특징은 기반 클래스(Shape)에도 있어야 한다
// => 그래야, "Shape*" 로 draw 를 호출할수 있다.
// => 문법적인 규칙이 아닌 "디자인 규칙"


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw Shape\n"; }
};

class Rect : public Shape
{
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
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v) 
				s->draw();	 
		}
	}
}

