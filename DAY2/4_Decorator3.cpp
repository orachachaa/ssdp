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


// ��� : Ŭ������ ����� �߰� �Ѱ�
// ���� : ��ü�� ��� �߰� �Ҷ� ���(������ �Ǵ� ���� �����)

class Emoticon : public IDraw
{
	IDraw* ps;	// �ٽ� : ������ �Ǵ� ���� ���( �� Ÿ�� �ȵ�)
	// �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴ� �°�
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

	Emoticon e(&ps); // ps ��ü�� "�̸�Ƽ��" ����� �߰�
	e.draw();

	Border b(&e);	// ps ��ü�� "Border �׸���" ��� �߰�
	b.draw();
}