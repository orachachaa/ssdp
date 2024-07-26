#include <iostream>
#include "add.h"

void foo()
{
	add2(2, 3);

	// inline 함수 라도 주소를 출력하면
	// add2 함수 자체도 기계어가 생성되어야 합니다.
	std::cout << &add2 << std::endl;
}