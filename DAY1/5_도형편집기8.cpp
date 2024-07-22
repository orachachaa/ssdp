#include <iostream>
#include <vector>

class Graphics
{
public:
	void init() {}
	void deinit() {}

	// 수백개의 그림을 그리는 함수들
};



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

	virtual void draw_imp(const Graphics& g)
	{
		std::cout << "draw Shape\n";
	}

	virtual Shape* clone() { return new Shape(*this); }

	virtual int get_area() { return 0; }
};


class Rect : public Shape
{
public:
	virtual void draw_imp(const Graphics& g) { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	virtual void draw_imp(const Graphics& g) { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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

