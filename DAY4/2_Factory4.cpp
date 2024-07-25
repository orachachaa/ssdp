#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = create_map.find(key);

		if (it != create_map.end())
		{
			p = it->second();
		}

		return p;
	}
};

class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*c)())
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};





class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	inline static AutoRegister ar{ 1, &Rect::create };
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	inline static AutoRegister ar{ 2, &Circle::create };
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




