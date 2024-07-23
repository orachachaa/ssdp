// function1.cpp
// => 메뉴 예제 완성을 위한 사전 지식 설명
#include <functional>
#include <iostream>
using namespace std::placeholders; // _1, _2, _3 ... 을 위해

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);  // foo는 4항 함수

	// std::bind : 인자를 고정한 새로운 함수를 만드는 도구
	
	// 사용법     : std::bind(M항함수주소, M개인자)

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // 4항 => 0항 함수로 변경
	f1();

	auto f2 = std::bind(&foo, 10, _1, 3, _2); // 4항 => 2항
	f2(5, 9); // foo(10, 5, 3, 9)


	auto f3 = std::bind(&foo, 3 , _3 , _2 , _1 ); 

	f3(9, 4, 7); // foo(3, 7, 9, 4) 가 되도록 위 ? 채우세요

	// 참고 : std::bind 의 반환 타입은, 인자의 형태에 따라
	//	     모두 다른 타입입니다. 그래서 auto 로 받았습니다.
}