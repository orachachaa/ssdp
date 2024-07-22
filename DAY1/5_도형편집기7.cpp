#include <iostream>
#include <vector>

// 화면에 그림을 그릴때 사용하는 클래스
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
	virtual int get_area() { return 0; }


	virtual void draw() 
	{ 
		// 도형 그림을 그리려면
		// #1. 그리기 전에 일반적인 초기화 과정을 수행하고
		Graphics g;
		g.init();

		// #2. 필요한 그림을 그리고
		std::cout << "draw Shape\n"; 

		// #3. 마무리 작업을 해야 한다고 가정해 봅시다.
		g.deinit();
	}




	virtual Shape* clone() { return new Shape(*this); }
};


class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

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

