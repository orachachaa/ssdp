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


// ��� �߰� Ŭ������(Decorator)�� ������ Ư¡�� ������ �ֽ��ϴ�.
// => ���� �׸��� ��� ��ġ(x,y) �� �׸��� �߰��Ұ��ΰ� ��
// => ��� Ŭ������ �����ϸ� �����ϴ�.

class Decorator : public IDraw
{
	IDraw* ps;
	int x = 0;
	int y = 0;
public:
	Decorator(IDraw* ps) : ps(ps) {}

	// ps �� private �̹Ƿ� ���⼭ �Ʒ� ó�� �׸��� �ְ� ����
	// => ���� ����� �߰� ���� ����.
	void draw() override
	{
		ps->draw(); 
	}
};

// ���� �پ��� ��� �߰� Ŭ���� ���鶧
// "Decorator" ���� ��ӹ����� �˴ϴ�.
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
