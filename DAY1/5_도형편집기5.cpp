// 4.cpp - 2�� ������ �ּ�����. 

#include <iostream>
#include <vector>

// �ٽ� #1. ������(Polymorphism) ����
// => OCP �� �����ϴ� ���� �ڵ� ��Ÿ�� ( main �ּ� ����)


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return 0; }


	virtual void draw() { std::cout << "draw Shape\n"; }
};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
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
				s->draw();	// "������ ǥ������ 
							//  ��Ȳ(��ü�� ����)�� ���� �ٸ��� ����"
							// => ������(Polymorphism)

							// ���ο� ����(Triangle) �� �߰��Ǿ
							// �� ������ �������� �ʽ��ϴ�.
							// => OCP ����
							
				// ��ü���� ����� 3���� Ư¡ : ĸ��ȭ, ���, ������
			}
		}
	}
}

