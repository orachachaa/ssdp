#include <iostream>
#include "add.h"

void foo()
{
	add2(2, 3);

	// inline �Լ� �� �ּҸ� ����ϸ�
	// add2 �Լ� ��ü�� ��� �����Ǿ�� �մϴ�.
	std::cout << &add2 << std::endl;
}