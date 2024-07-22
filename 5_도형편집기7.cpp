// 15page ~ 
#include <iostream>
#include <vector>

class Graphics {
public:
	void init() {}
	void deinit() {}
};

class Shape {
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	virtual void draw_imp(const Graphics& g)
	{
		std::cout << "draw Shape\n";
	}

	void draw()
	{
		Graphics g;
		g.init();

		draw_imp(g);

		g.deinit();
	}

	virtual Shape* clone() { return new Shape(*this); }
};

class Rect : public Shape {
public:
	virtual void draw_imp(const Graphics& g) { std::cout << "draw Rect\n"; }
	Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape {
public:
	virtual void draw_imp(const Graphics& g) { std::cout << "draw Circle\n"; }
	Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector <Shape*> v;

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
		else if (cmd == 0)
		{
			std::cout << "몇 번째 만들었던 도형을 복제 할까요? ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());
		}
	}
}

