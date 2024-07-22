#include <iostream>
#include <vector>

class Graphics
{
public:
	void init() {}
	void deinit() {}

	// 수백개의 그림을 그리는 함수들
};


class NotImplemented {}; // 예외 전달용으로 만든 클래스

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	void draw()
	{
		Graphics g;
		g.init();
		draw_imp(g);
		g.deinit();
	}
	
	// 가상함수     : 파생클래스가 override 하지 않으면 기본 구현 제공한다는 의도
	// 순수가상함수 : 파생클래스가 반드시 구현을 제공해야 한다고 지시 

	// #1. draw_imp 는 순수 가상함수로 해야 합니다.
	virtual void draw_imp(const Graphics& g) = 0;


	// #2. clone 도
	// => 순수 가상함수로 해도 되고
	// => 다른 기법도 가능(기본 구현은 예외 발생)
//	virtual Shape* clone() = 0;

	virtual Shape* clone() { throw NotImplemented(); }
	// => 위코드 의도
	// 1. clone() 을 override 하지 않고 사용하면 "예외발생"
	// 2. clone() 을 override 하고      사용하면 "문제없음"
	// 3. clone() 을 override 하지 않고 사용하지도 않으면 "문제 없음"
	// 즉, 필요하면 만들라는 것!
	// 순수 가상함수였다면, "필요 없어도, 파생클래스가 구현을 제공해야 합니다."
	

	// #3. 또다른 기법
	// => 기본 구현으로 실패를 의미(-1 또는 0등)하는 약속된 값 반환
//	virtual int get_area() = 0; // 파생 클래스는 반드시 구현해야 한다.
//	virtual int get_area() { throw NotImplemented(); } // 구현하지 않았으면
													   // 사용도 하지 말라
	virtual int get_area() { return -1; }	// 구현하지 않고 사용하면
											// 예외는 없고
											// 실패를 의미 하는 값 반환
};






class Rect : public Shape
{
public:
	void draw_imp(const Graphics& g) override
	{ 
		std::cout << "draw Rect\n"; 
	}

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp(const Graphics& g) override { std::cout << "draw Circle\n"; }

	Shape* clone() override { return new Circle(*this); }
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
				s->draw();
			}
		}
		else if (cmd == 0)
		{
			std::cout << "몇번째 만들었던 도형을 복제 할까요 ?";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}

