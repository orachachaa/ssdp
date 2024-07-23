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
	void(*f)(int);
	f = &f1; // ok
	f = &f2; // error. 인자의 갯수가 다릅니다.
	//-------------------------------------
}