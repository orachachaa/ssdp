// add.h, add.cpp
// foo.h, foo.cpp
// 모두 빌드에 포함 해 주세요

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
