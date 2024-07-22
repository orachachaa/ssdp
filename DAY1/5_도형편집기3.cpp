#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}
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
			{
				// 해결책 #1. 캐스팅!
				// => Rect 또는 Circle 객체 일수 있으므로
				// => dynamic_cast 로 조사후. 
				// => 해당 타입으로 캐스팅해서 사용

				if ( dynamic_cast<Rect*>(s) != nullptr )
					static_cast<Rect*>(s)->draw();
				
				else if (dynamic_cast<Circle*>(s) != nullptr)
					static_cast<Circle*>(s)->draw();

			}
		}
	}
}
// 컴파일해서 실행해 보세요
// 1, 2, 1, 2, 9 순서로 입력해 보세요

