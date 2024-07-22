#include <iostream>
#include <vector>

// �ٽ� : template method ������ ����

// => ��� �Ļ� Ŭ������ ����� �������� �ڵ带 ���� �Լ�(�޼ҵ�)
// => ���ؾ� �ϴ� �Ϻ� �ܰ踦 �����Լ��� �ؼ�
// => �Ļ� Ŭ������ �����Ҽ� �ְ� �Ѵ�.
// => �Ϻ� ��Ģ�� �Ļ� Ŭ������ �����Ҽ� �ְ��ϴ� ����.
// => ���� �θ� ���Ǵ� ����.



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

	// �ٽ� : ���뼺�� �������� �и�
	// => "������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� �и��Ѵ�."
	// => ���ؾ� �ϴ� ���� ������ �����Լ��� �и��Ѵ�.

	virtual void draw_imp(const Graphics& g)
	{
		// g �� ����ؼ� �׸���.. 
		std::cout << "draw Shape\n"; 
	}

	void draw() 
	{ 
		// ���� �׸��� �׸�����
		// #1. �׸��� ���� �Ϲ����� �ʱ�ȭ ������ �����ϰ�
		Graphics g;
		g.init();

		// #2. �ʿ��� �׸��� �׸���
		draw_imp(g);

		// #3. ������ �۾��� �ؾ� �Ѵٰ� ������ ���ô�.
		g.deinit();
	}




	virtual Shape* clone() { return new Shape(*this); }
};


class Rect : public Shape
{
public:
	virtual void draw_imp(const Graphics& g) { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	virtual void draw_imp(const Graphics& g) { std::cout << "draw Circle\n"; }

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

