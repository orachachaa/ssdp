#include <iostream>
#include <vector>

// 핵심 #1. 디자인 패턴 이란 ?
// => 1995년에 발간된 책의 제목
// => 4명의 저자 ( Gangs Of Four 라고 불리는 )

// => 당시에 유행하던 유명한 "C++ 오픈소스"를 분석해서
// => 공통으로 사용되는 코딩 패턴에 "이름"을 부여 한것

// => 특정 문제를 해결하는데, 사용하던 공통의 기법에 부여된 이름
//    23개의 이름이 있습니다.

// ex) "undo/redo" 기능이 필요 하다 
// => 이미 널리 알려진 기법이 있습니다.
// => 이 기법을 먼저 학습하고, 자신에 환경에 맞게 적용하면 됩니다.
// => "command" 패턴을 학습하면 됩니다.(목요일)


// 2. prototype 패턴
// => 객체를 먼저 만들고, 복사를 통해서 객체를 만드는 기술
// => clone 가상함수
// => 보다 좋은 예제는 목요일날. 



// 3. 리팩토링(refactoring, 기존 코드를 이쁘게 정리하는 것)에서 
//    중요한 개념입니다. 생각해 보세요

//    "replace conditional with polymorphism"
//	  "제어문(if, switch) 을 다형성(가상함수)로 변경해라"
//    도형편집기3.cpp => 도형편집기4.cpp 로 변경해라.



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

