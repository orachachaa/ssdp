#include <iostream>

// PhotoSticker : 중요한 기능을 수행하는 클래스
// Emoticon, Border : PhotoSticker 객체에 기능 을 추가하는 클래스(Decorator)

// 기능추가의 중첩을 위해서는
// => PhotoSticker 와  Decorator 는 공통의 기반 클래스가 있어야 한다.

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



class Emoticon : public IDraw
{
	IDraw* ps;
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

	Emoticon e(&ps); 
	e.draw();

	Border b(&e);	
	b.draw(); 
}
