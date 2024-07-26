// add.h
#include <iostream>

int add1(int a, int b);


inline int add2(int a, int b)
{
	std::cout << "add2\n";
	return a + b;
}

