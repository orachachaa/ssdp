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


// 핵심 정리

// #1. inline 함수는 구현자체가 "헤더 파일" 에 있어야 합니다

// #2. 일반 함수는 구현 자체를 헤더에 넣으면 안됩니다.


// #3. inline 의 정확한 의미

// 1. inline 치환을 해달라(컴파일 옵션에 따라 달라질수 있음)

// 2. "multiple definition 을 허용해 달라"
//    => 최종 결과는 실행파일에서 한개만 가지도록 컴파일러(링커)가 보장.
//    => cppreference.com 에서 inline 검색