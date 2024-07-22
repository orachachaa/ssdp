#include <iostream>
#include <vector>

class Graphics
{
public:
	void init() {}
	void deinit() {}

	// 수백개의 그림을 그리는 함수들
};


class NotImplemented {}; 

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


	virtual void draw_imp(const Graphics& g) = 0;
	virtual Shape* clone() { throw NotImplemented(); }								
	virtual int get_area() { return -1; }	
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
		// 생각해볼 문제 #1. undo/redo 기능을 구현하려면 어떻게 해야 할까요 ?
		// => "command 패턴" 을 사용하면 됩니다.(목요일날 구현)

		// 생각해볼 문제 #2. 객체의 생성 과정을 OCP 를 만족하게 할수 없을까 ?
		// => 새로운 도형이 추가되어도 아래 코드가 수정되지 않게
		// => "Factory" 를 사용하면 됩니다. (목요일날 구현)
		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw(); // OCP 만족, 새로운 도형이 추가되어도 수정되지 않는다.
			}
		}
		else if (cmd == 0)
		{
			std::cout << "몇번째 만들었던 도형을 복제 할까요 ?";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // OCP 만족, 새로운 도형이 추가되어도 수정되지 않는다.

		}
	}
}

