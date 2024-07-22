#include <iostream>
#include <vector>

class Graphics
{
public:
	void init() {}
	void deinit() {}

	// ���鰳�� �׸��� �׸��� �Լ���
};


class NotImplemented {}; 

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


	virtual void draw_imp(const Graphics& g) = 0;
	virtual Shape* clone() { throw NotImplemented(); }								
	virtual int get_area() { return -1; }	
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
		// �����غ� ���� #1. undo/redo ����� �����Ϸ��� ��� �ؾ� �ұ�� ?
		// => "command ����" �� ����ϸ� �˴ϴ�.(����ϳ� ����)

		// �����غ� ���� #2. ��ü�� ���� ������ OCP �� �����ϰ� �Ҽ� ������ ?
		// => ���ο� ������ �߰��Ǿ �Ʒ� �ڵ尡 �������� �ʰ�
		// => "Factory" �� ����ϸ� �˴ϴ�. (����ϳ� ����)
		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw(); // OCP ����, ���ο� ������ �߰��Ǿ �������� �ʴ´�.
			}
		}
		else if (cmd == 0)
		{
			std::cout << "���° ������� ������ ���� �ұ�� ?";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // OCP ����, ���ο� ������ �߰��Ǿ �������� �ʴ´�.

		}
	}
}

