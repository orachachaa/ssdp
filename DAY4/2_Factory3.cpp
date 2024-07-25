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

// 공장에 도형을 자동으로 등록하기 위한 클래스
class AutoRegister
{
public:
	AutoRegiter(int key, Shape* (*c)())
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// 전역변수의 생성자가 언제 호출되는지 생각해보세요
// => main 함수보다 먼저 호출
//AutoRegister ar(1, &Rect::create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해보세요
	// => 모든 객체 공유
	// => Rect 객체를 한개도 만들지 않아도, 프로그램 시작시에 메모리에 생성
	// => 즉, ar 생성자는 main 함수 이전에 호출됨.
	inline static AutoRegister ar{ 1, &Rect::create }; 
							// () 아닌 {}로 해야 합니다. 
};
// Rect::ar 의 생성자가 먼저 한번 호출
//					 => 결국, 객체 초기화가 아닌
//					    모든 객체에 공통으로 사용할 초기화
//						"클래스 생성자" 개념
//Rect* r1 = new Rect; // 생성자 호출
//Rect* r2 = new Rect; // 생성자 호출
//Rect* r3 = new Rect; // 생성자 호출, 즉, 생성자는 객체당 한번씩 호출

// C#
class Car
{
	public Car() {} // instance 생성자
	static Car() {} // static 생성자
};

Car c1 = new Car(); // static 생성자 호출
					// instance 생성자 호출
Car c2 = new Car(); // instance 생성자 호출





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




