#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create()  { return new Rect; }
	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	static Shape* create() { return new Circle; }

	Shape* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map; 

public:
	void register_sample(int key, Shape* s)
	{
		prototype_map[key] = s;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = prototype_map.find(key);

		if (it != prototype_map.end())
		{
			p = it->second->clone();
		}

		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에는 제품(도형)을 등록후에 사용해야 합니다.
	// => 아래 코드는 공장에 "생성함수"를 등록하고 있습니다.
	// => 결국, "클래스" 를 등록하는 의미 입니다.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


	// 이번에는 "생성함수" 가 아닌
	// => 자주 사용되는 견본객체를 공장에 등록해 봅시다.
	// => 각 객체를 만들때 생성자 인자 등이 복잡하다고 생각해 보세요
	Rect* redRect = new Rect;	
	Rect* blueRect = new Rect;
	Circle* redCircle = new  Circle;

	factory.register_sample(1, redRect);
	factory.register_sample(2, blueRect);
	factory.register_sample(3, redCircle);



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


// Prototype 패턴
// => 자주 사용되는 객체의 견본을 미리 생성해서 보관하고 있다가
//    복사를 통해서 새로운 객체를 생성하는 기법

