#include <iostream>

// PhotoSticker : �߿��� ����� �����ϴ� Ŭ����
// Emoticon, Border : PhotoSticker ��ü�� ��� �� �߰��ϴ� Ŭ����(Decorator)

// ����߰��� ��ø�� ���ؼ���
// => PhotoSticker ��  Decorator �� ������ ��� Ŭ������ �־�� �Ѵ�.

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
