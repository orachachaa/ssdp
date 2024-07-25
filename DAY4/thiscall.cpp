class Point
{
	int x, y;
public:
	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	static void foo(int a, int b) {}
};

int main()
{
	Point p1, p2;

	p1.set(10, 20);

	//void(*f)(int, int) = &Point::set;

	void(*f)(int, int) = &Point::foo;


}