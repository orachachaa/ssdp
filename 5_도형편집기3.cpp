// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape {
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape {
public:
	void draw() { std::cout << "draw Circle\n"; }
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
			for (auto s : v) {
				if (dynamic_cast<Rect *>(s) != nullptr)
					static_cast<Rect *>(s)->draw();
				else if (dynamic_cast<Circle*>(s) != nullptr)
					static_cast<Circle*>(s)->draw();
			}
		}
	}
}

