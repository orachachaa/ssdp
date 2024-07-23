#include <functional>
#include <iostream>

using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);

	auto f1 = std::bind(&foo, 1, 2, 3, 4);
	f1();

	auto f2 = std::bind(&foo, 10, std::placeholders::_1, 3, std::placeholders::_2);
	f2(5, 9); // foo(10, 5, 3, 9)

	auto f3 = std::bind(&foo, 3, _3, _1, _2);
	f3(9, 4, 7); foo(3, 7, 9, 4);
}