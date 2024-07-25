// thiscall

// �ٽ� 1. ��� �Լ��� ���ڷ� this�� �߰��˴ϴ�.
//     2. static ��� �Լ� �� this �� �߰����� �ʽ��ϴ�.

class Point
{
	int x, y;
public:
	void set(int a, int b)// void set(Point* this, int a, int b)
	{
		x = a;				// this->x = a;
		y = b;				// this->y = b;
	}

	static void foo(int a, int b) {}
};

int main()
{
	Point p1, p2;

	p1.set(10, 20); // ������ ��Ȯ�� �˾� ���ô�.
					// set(&p1, 10, 20)

	// �Լ������Ϳ� ��� �Լ�
	void(*f)(int, int) = &Point::set;	// error.
										// set�� ���ڴ� 2�� �ƴ�!!
										// this �߰���

	void(*f)(int, int) = &Point::foo;	// ok. ���� 2�� ����.
										// static ��� �Լ��� this �߰� �ȵ�
}

/*
p.set(10, 20); // set(&p, 10, 20)
				// std::invoke(&Point::set, p, 10, 20)

class Point
{
	void set(int a, int b) {}

	void set(Point* this, int a, int b) {} // error

	void set(this Point* self, int a, int b) // ok. C++23 ����!
	{								// explicit object parameter ����
									// ���� : "deducing this"
		self.x = a;
	}
};
*/