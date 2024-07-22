// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 1개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다.
// 의도 : 파생 클래스 제작자에게 특정 이름의 함수를 반드시 만들라고 지시하는것
//		  모든 도형이 지켜야 하는 규칙을 만드는 것.
//		  모든 도형은 "draw 함수를 만들어야 한다" 라는 규칙
class Shape
{
public:
	virtual void draw() = 0;	// 순수 가상함수(pure virtual function)
								// => 구현부가 없고, "=0" 으로 표기							 
};

class Rect : public Shape
{
	// draw() 의 구현을 제공하지 않으면 Rect 도 추상.
	// draw() 의 구현을 제공하면 추상이 아님.
public:
	void draw() override {} // 이렇게 하면 Rect 는 추상 아님. 객체 생성 가능
};

int main()
{
	Shape  s; // error
	Shape* p; // ok. 
	Rect  r;  // ok.
}
