#include <iostream>
#include <vector>


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
				s->draw();	
			}
		}
		else if (cmd == 0)
		{
			std::cout << "몇번째 만들었던 도형을 복제 할까요 ?";
			int k;
			std::cin >> k; 

			// k번째 만들었던 도형과 완전히 동일한 도형을 한개 더 만들어서
			// v 에 추가!!

			// 어떻게 구현해야 할까요 ?
			// k번째 도형은 어떤 도형일까요 ?
		}
	}
}

