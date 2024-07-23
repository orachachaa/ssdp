// Decorator - 65 page
#include <iostream>

// PhotoSticker : 중요한 기능을 수행하는 클래스
// Emoticon, Boarder : PhotoSticker 객체에 기능을 추가하는 클래스

// PhotoSticker와 Decorator는 공통의 기반 클래스가 있어야 한다.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};

class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


// 상속 : 클래스에 기능을 추가 한것
// 포함 : 객체에 기능 추가 할때 사용(포인터 또는 참조 멤버로)

class Emoticon : public IDraw
{
	IDraw* ps;	// 핵심 : 포인터 또는 참조 멤버( 값 타입 안됨)
	// 의도 : 외부에 이미 생성된 객체를 가리키겠다 는것
public:
	Emoticon(IDraw* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "###############\n";
		ps->draw();
		std::cout << "###############\n";
	}
};

class Border : public IDraw
{
	IDraw* ps;
public:
	Border(IDraw* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "===============\n";
		ps->draw();
		std::cout << "===============\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();

	Emoticon e(&ps); // ps 객체에 "이모티콘" 기능을 추가
	e.draw();

	Border b(&e);	// ps 객체에 "Border 그리기" 기능 추가
	b.draw();
}