// thiscall

// 핵심 1. 멤버 함수는 인자로 this가 추가됩니다.
//     2. static 멤버 함수 는 this 가 추가되지 않습니다.

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

	p1.set(10, 20); // 원리를 정확히 알아 봅시다.
					// set(&p1, 10, 20)

	// 함수포인터와 멤버 함수
	void(*f)(int, int) = &Point::set;	// error.
										// set의 인자는 2개 아님!!
										// this 추가됨

	void(*f)(int, int) = &Point::foo;	// ok. 인자 2개 맞음.
										// static 멤버 함수는 this 추가 안됨
}

/*
p.set(10, 20); // set(&p, 10, 20)
				// std::invoke(&Point::set, p, 10, 20)

class Point
{
	void set(int a, int b) {}

	void set(Point* this, int a, int b) {} // error

	void set(this Point* self, int a, int b) // ok. C++23 부터!
	{								// explicit object parameter 문법
									// 별명 : "deducing this"
		self.x = a;
	}
};
*/