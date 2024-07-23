#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍
// => 프로그램의 모든 요소를 객체로 생각하는 것
// => 프로그램에서 필요한 타입을 먼저 설계해야 한다.

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 51);

	m1.command(); // 메뉴를 선택하면 "command" 가 호출된다고 가정.
}




