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

	static Shape* create() { return new Rect; }

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
	MAKE_SINGLETON(ShapeFactory);

	using CREATOR = Shape * (*)();

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

//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

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



