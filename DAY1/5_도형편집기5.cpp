// 4.cpp - 2번 복사후 주석제거. 

#include <iostream>
#include <vector>

// 핵심 #1. 다형성(Polymorphism) 개념
// => OCP 를 만족하는 좋은 코딩 스타일 ( main 주석 참고)


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return 0; }


	virtual void draw() { std::cout << "draw Shape\n"; }
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
				s->draw();	// "동일한 표현식이 
							//  상황(객체의 종류)에 따라 다르게 동작"
							// => 다형성(Polymorphism)

							// 새로운 도형(Triangle) 이 추가되어도
							// 이 한줄은 수정되지 않습니다.
							// => OCP 만족
							
				// 객체지향 언어의 3가지 특징 : 캡슐화, 상속, 다형성
			}
		}
	}
}

