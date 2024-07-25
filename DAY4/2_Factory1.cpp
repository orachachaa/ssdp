#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// 도형을 만드는 팩토리

// 도형의 생성은 공장을 통해서만 할수 있도록 하면
// => 새로운 도형이 추가되었을때, 공장만 수정하면 됩니다.
// => 코드 수정을 최소화 할수 있습니다.

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;


		if (cmd > 0 && cmd < 8) // 1 ~ 7 을 도형 번호로 예약
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}


		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




