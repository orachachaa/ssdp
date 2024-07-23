// function1.cpp
// => 메뉴 예제 완성을 위한 사전 지식 설명
#include <functional>
#include <iostream>

void foo(int a, int b int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);  // foo는 4항 함수

	// std::bind : 인자를 고정한 새로운 함수를 만드는 도구
	
	// 사용법     : std::bind(M항함수주소, M개인자)

	auto f1 = std::bind(&foo, 1, 2, 3, 4);
	f1();

}