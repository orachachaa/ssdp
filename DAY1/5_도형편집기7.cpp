#include <iostream>
#include <vector>

// 핵심 : template method 디자인 패턴

// => 모든 파생 클래스에 적용될 공통적인 코드를 담은 함수(메소드)
// => 변해야 하는 일부 단계를 가상함수로 해서
// => 파생 클래스가 변경할수 있게 한다.
// => 일부 규칙을 파생 클래스가 결정할수 있게하는 패턴.
// => 가장 널리 사용되는 패턴.



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

	// 핵심 : 공통성과 가변성의 분리
	// => "변하지 않은 코드 내부에 있는 변해야 하는 부분을 분리한다."
	// => 변해야 하는 것을 별도의 가상함수를 분리한다.

	virtual void draw_imp(const Graphics& g)
	{
		// g 를 사용해서 그리기.. 
		std::cout << "draw Shape\n"; 
	}

	void draw() 
	{ 
		// 도형 그림을 그리려면
		// #1. 그리기 전에 일반적인 초기화 과정을 수행하고
		Graphics g;
		g.init();

		// #2. 필요한 그림을 그리고
		draw_imp(g);

		// #3. 마무리 작업을 해야 한다고 가정해 봅시다.
		g.deinit();
	}




	virtual Shape* clone() { return new Shape(*this); }
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

