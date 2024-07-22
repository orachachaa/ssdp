#include <iostream>
#include <vector>

class Graphics
{
public:
	void init() {}
	void deinit() {}

	// ���鰳�� �׸��� �׸��� �Լ���
};


class NotImplemented {}; // ���� ���޿����� ���� Ŭ����

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	void draw()
	{
		Graphics g;
		g.init();
		draw_imp(g);
		g.deinit();
	}
	
	// �����Լ�     : �Ļ�Ŭ������ override ���� ������ �⺻ ���� �����Ѵٴ� �ǵ�
	// ���������Լ� : �Ļ�Ŭ������ �ݵ�� ������ �����ؾ� �Ѵٰ� ���� 

	// #1. draw_imp �� ���� �����Լ��� �ؾ� �մϴ�.
	virtual void draw_imp(const Graphics& g) = 0;


	// #2. clone ��
	// => ���� �����Լ��� �ص� �ǰ�
	// => �ٸ� ����� ����(�⺻ ������ ���� �߻�)
//	virtual Shape* clone() = 0;

	virtual Shape* clone() { throw NotImplemented(); }
	// => ���ڵ� �ǵ�
	// 1. clone() �� override ���� �ʰ� ����ϸ� "���ܹ߻�"
	// 2. clone() �� override �ϰ�      ����ϸ� "��������"
	// 3. clone() �� override ���� �ʰ� ��������� ������ "���� ����"
	// ��, �ʿ��ϸ� ������ ��!
	// ���� �����Լ����ٸ�, "�ʿ� ���, �Ļ�Ŭ������ ������ �����ؾ� �մϴ�."
	

	// #3. �Ǵٸ� ���
	// => �⺻ �������� ���и� �ǹ�(-1 �Ǵ� 0��)�ϴ� ��ӵ� �� ��ȯ
//	virtual int get_area() = 0; // �Ļ� Ŭ������ �ݵ�� �����ؾ� �Ѵ�.
//	virtual int get_area() { throw NotImplemented(); } // �������� �ʾ�����
													   // ��뵵 ���� ����
	virtual int get_area() { return -1; }	// �������� �ʰ� ����ϸ�
											// ���ܴ� ����
											// ���и� �ǹ� �ϴ� �� ��ȯ
};






class Rect : public Shape
{
public:
	void draw_imp(const Graphics& g) override
	{ 
		std::cout << "draw Rect\n"; 
	}

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp(const Graphics& g) override { std::cout << "draw Circle\n"; }

	Shape* clone() override { return new Circle(*this); }
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
			std::cout << "���° ������� ������ ���� �ұ�� ?";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}

