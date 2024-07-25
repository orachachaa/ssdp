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

	// 자신의 객체를 만들수 있는 static 멤버 함수는 아주 유용하게 사용됩니다.
	// => C++, C#, Java, Rust 등 대부분의 언어에서 볼수 있는 기술
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Shape* s1 = new Rect;
// 2. Shape* s2 = Rect::create();









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
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


		if (cmd > 0 && cmd < 8) 
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




