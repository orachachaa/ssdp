#include <iostream>
#include <vector>

// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
public:
	void init() {}
	void deinit() {}

	// ���鰳�� �׸��� �׸��� �Լ���
};



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return 0; }


	virtual void draw() 
	{ 
		// ���� �׸��� �׸�����
		// #1. �׸��� ���� �Ϲ����� �ʱ�ȭ ������ �����ϰ�
		Graphics g;
		g.init();

		// #2. �ʿ��� �׸��� �׸���
		std::cout << "draw Shape\n"; 

		// #3. ������ �۾��� �ؾ� �Ѵٰ� ������ ���ô�.
		g.deinit();
	}




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

			v.push_back(v[k]->clone()); 
	
		}
	}
}

