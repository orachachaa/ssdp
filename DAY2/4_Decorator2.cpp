// Decorator - 65 page
#include <iostream>

// PhotoSticker : ��ƼĿ ������ ��� ������ ������

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


// ��� : Ŭ������ ����� �߰� �Ѱ�
// ���� : ��ü�� ��� �߰� �Ҷ� ���(������ �Ǵ� ���� �����)

class Emoticon 
{
	PhotoSticker* ps;	// �ٽ� : ������ �Ǵ� ���� ���( �� Ÿ�� �ȵ�)
						// �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴ� �°�
public:
	Emoticon(PhotoSticker* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "###############\n";	
		ps->draw();				
		std::cout << "###############\n";
	}
};

class Border 
{
	PhotoSticker* ps;
public:
	Border(PhotoSticker* ps) : ps(ps) {}

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

	Border b(&ps);	// ps ��ü�� "Border �׸���" ��� �߰�
	b.draw();
}
