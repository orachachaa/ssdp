// Decorator - 65 page
#include <iostream>

// PhotoSticker : �߿��� ����� �����ϴ� Ŭ����
// Emoticon, Boarder : PhotoSticker ��ü�� ����� �߰��ϴ� Ŭ����

// PhotoSticker�� Decorator�� ������ ��� Ŭ������ �־�� �Ѵ�.

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

class Decorator : public IDraw
{
	IDraw* ps;
	int x = 0;
	int y = 0;
public:
	Decorator(IDraw* ps) : ps(ps) {}

	void draw() override
	{
		ps->draw();
	}
};

// ��� : Ŭ������ ����� �߰� �Ѱ�
// ���� : ��ü�� ��� �߰� �Ҷ� ���(������ �Ǵ� ���� �����)

class Emoticon : public Decorator
{
	// �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴ� �°�
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
	IDraw* ps;
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

	Emoticon e(&ps); // ps ��ü�� "�̸�Ƽ��" ����� �߰�
	e.draw();

	Border b(&e);	// ps ��ü�� "Border �׸���" ��� �߰�
	b.draw();
}