// add.h, add.cpp
// foo.h, foo.cpp
// ��� ���忡 ���� �� �ּ���

#include <iostream>
#include "add.h"
#include "foo.h"

int main()
{
	add1(1, 2);
	add2(1, 2);

	foo();

	std::cout << "main : " << &add2 << std::endl;
}
