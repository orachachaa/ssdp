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

// ���忡 ������ �ڵ����� ����ϱ� ���� Ŭ����
class AutoRegister
{
public:
	AutoRegiter(int key, Shape* (*c)())
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// ���������� �����ڰ� ���� ȣ��Ǵ��� �����غ�����
// => main �Լ����� ���� ȣ��
//AutoRegister ar(1, &Rect::create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static ��� ����Ÿ�� Ư¡�� �����غ�����
	// => ��� ��ü ����
	// => Rect ��ü�� �Ѱ��� ������ �ʾƵ�, ���α׷� ���۽ÿ� �޸𸮿� ����
	// => ��, ar �����ڴ� main �Լ� ������ ȣ���.
	inline static AutoRegister ar{ 1, &Rect::create }; 
							// () �ƴ� {}�� �ؾ� �մϴ�. 
};
// Rect::ar �� �����ڰ� ���� �ѹ� ȣ��
//					 => �ᱹ, ��ü �ʱ�ȭ�� �ƴ�
//					    ��� ��ü�� �������� ����� �ʱ�ȭ
//						"Ŭ���� ������" ����
//Rect* r1 = new Rect; // ������ ȣ��
//Rect* r2 = new Rect; // ������ ȣ��
//Rect* r3 = new Rect; // ������ ȣ��, ��, �����ڴ� ��ü�� �ѹ��� ȣ��

// C#
class Car
{
	public Car() {} // instance ������
	static Car() {} // static ������
};

Car c1 = new Car(); // static ������ ȣ��
					// instance ������ ȣ��
Car c2 = new Car(); // instance ������ ȣ��





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};







int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




