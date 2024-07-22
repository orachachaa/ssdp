#include <iostream>
#include <vector>

// �ٽ� #1. ������ ���� �̶� ?
// => 1995�⿡ �߰��� å�� ����
// => 4���� ���� ( Gangs Of Four ��� �Ҹ��� )

// => ��ÿ� �����ϴ� ������ "C++ ���¼ҽ�"�� �м��ؼ�
// => �������� ���Ǵ� �ڵ� ���Ͽ� "�̸�"�� �ο� �Ѱ�

// => Ư�� ������ �ذ��ϴµ�, ����ϴ� ������ ����� �ο��� �̸�
//    23���� �̸��� �ֽ��ϴ�.

// ex) "undo/redo" ����� �ʿ� �ϴ� 
// => �̹� �θ� �˷��� ����� �ֽ��ϴ�.
// => �� ����� ���� �н��ϰ�, �ڽſ� ȯ�濡 �°� �����ϸ� �˴ϴ�.
// => "command" ������ �н��ϸ� �˴ϴ�.(�����)


// 2. prototype ����
// => ��ü�� ���� �����, ���縦 ���ؼ� ��ü�� ����� ���
// => clone �����Լ�
// => ���� ���� ������ ����ϳ�. 



// 3. �����丵(refactoring, ���� �ڵ带 �̻ڰ� �����ϴ� ��)���� 
//    �߿��� �����Դϴ�. ������ ������

//    "replace conditional with polymorphism"
//	  "���(if, switch) �� ������(�����Լ�)�� �����ض�"
//    ����������3.cpp => ����������4.cpp �� �����ض�.



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return 0; }


	virtual void draw() { std::cout << "draw Shape\n"; }

	// �ڽŰ� ������ ��ü�� ����� �����Լ��� 
	// ���� �����ϰ� Ȱ��˴ϴ�.
	// => ��������ڷ� ����� �� �ڽŰ� ������ ������ ��ü ����
	virtual Shape* clone() { return new Shape(*this); }
};


class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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

			// k��° ������� ������ ������ ������ ������ �Ѱ� �� ����
			// v �� �߰�!!

			// ��� �����ؾ� �ұ�� ?
			// k��° ������ � �����ϱ�� ?

			// �Ʒ� �ذ�å�� "OCP" �� �������� ���ϴ� ������ ������
			/*
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				// v[k]�簢���̴�
				// �簢���� ���� ����� v[k]�� ��� �Ӽ��� �����ϰ� ��������
			}
			*/

			// �ذ�å : ������

			v.push_back(v[k]->clone()); // ok.. ������
										// k��° ������ � �������� �������ʿ� ����.
										// ���ο� ������ �߰��Ǿ �� �ڵ��
										// ����� �ʿ� ����.
										// "OCP ����"
		}
	}
}

