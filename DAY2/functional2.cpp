#include <functional>
#include <iostream>

using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

void f1(int) {}
void f2(int, int) {}

int main()
{
	//void(*f)(int);
	//f = &f1;
	//f2 = &f2;

	std::function<void(int)> f;
	f = &f1;
	f(10);

	//f = &f2;
	f = std::bind(&f2, 3, _1);
	f(10);
}