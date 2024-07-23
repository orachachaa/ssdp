// function1.cpp
// => 메뉴 예제 완성을 위한 사전 지식 설명
#include <functional>
#include <iostream>
using namespace std::placeholders; // _1, _2, _3 ... 을 위해

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

void f1(int)      {}
void f2(int, int) {}

int main()
{
	// C 함수 포인터는 유연성이 없습니다.
//	void(*f)(int);
//	f = &f1; // ok
//	f = &f2; // error. 인자의 갯수가 다릅니다.
	//-------------------------------------

	// std::function : 함수포인터와 유사한 용도로 사용하기 위한
	//					C++ 표준 클래스
	std::function<void(int)> f;

	f = &f1; // ok
	f(10);   // f1(10) 결국, 함수 포인터와 동일한 사용법.

	

	// 핵심 : std::function 은 std::bind 의 반환 값을 보관 가능

//	f = &f2; // error. f2는 인자가 2개. 

	f = std::bind(&f2, 3, _1); // ok. 2항 => 1항으로 변경
	f(10); // f2(3, 10)
}