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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신의 객체를 만들수 있는 static 멤버 함수는 아주 유용하게 사용됩니다.
	// => C++, C#, Java, Rust 등 대부분의 언어에서 볼수 있는 기술
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Shape* s1 = new Rect;			// 반드시 클래스 이름을 알아야 합니다.
// 2. Shape* s2 = Rect::create();	// 클래스 이름을 몰라도, 함수 주소만 알면됩니다.

// C++ 은 "클래스" 을 자료구조에 보관할수 없습니다.
// v.push_back("Rect"); // 클래스가 아닌 문자열을 보관한것
					 // => 문자열 "Rect"로 는 객체 생성 안됩니다.

// 하지만, 함수 포인터(주소) 는 자료구조에 보관가능합니다.
// v.push_back(&Rect::create); // 보관된 주소로 Rect 객체 생성 가능







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)();

	std::map<int, CREATOR> create_map; // [도형번호, 생성함수] 를 보관

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
			p = it->second(); // second 가 value, 즉, 생성함수
		}

		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에는 제품(도형)을 등록후에 사용해야 합니다.
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




