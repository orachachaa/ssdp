#include <iostream>

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


// 기능 추가 클래스들(Decorator)은 공통의 특징이 있을수 있습니다.
// => 원본 그림의 어느 위치(x,y) 에 그림을 추가할것인가 등
// => 기반 클래스로 제공하면 좋습니다.

class Decorator : public IDraw
{
	IDraw* ps;
	int x = 0;
	int y = 0;
public:
	Decorator(IDraw* ps) : ps(ps) {}

	// ps 가 private 이므로 여기서 아래 처럼 그릴수 있게 제공
	// => 아직 기능은 추가 되지 않음.
	void draw() override
	{
		ps->draw(); 
	}
};

// 이제 다양한 기능 추가 클래스 만들때
// "Decorator" 에서 상속받으면 됩니다.
class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "###############\n";
		Decorator::draw();
		std::cout << "###############\n";
	}
};

class Border : public Decorator
{
public:
	Border(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "===============\n";
		Decorator::draw();
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
