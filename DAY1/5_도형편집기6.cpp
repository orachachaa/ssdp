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

	// 자신과 동일한 객체를 만드는 가상함수는 
	// 아주 유용하게 활용됩니다.
	// => 복사생성자로 만들면 내 자신과 완전히 동일한 객체 생성
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

			// k번째 만들었던 도형과 완전히 동일한 도형을 한개 더 만들어서
			// v 에 추가!!

			// 어떻게 구현해야 할까요 ?
			// k번째 도형은 어떤 도형일까요 ?

			// 아래 해결책은 "OCP" 를 만족하지 못하는 안좋은 디자인
			/*
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				// v[k]사각형이다
				// 사각형을 새로 만들고 v[k]의 모든 속성과 동일하게 설정하자
			}
			*/

			// 해결책 : 다형성

			v.push_back(v[k]->clone()); // ok.. 다형성
										// k번째 도형이 어떤 종류인지 조사할필요 없다.
										// 새로운 도형이 추가되어도 이 코드는
										// 변경될 필요 없다.
										// "OCP 만족"
		}
	}
}

