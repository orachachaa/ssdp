#include <iostream>
#include "add.h"

void foo()
{
	add2(2, 3);

	std::cout << "foo : " << &add2 << std::endl;
}