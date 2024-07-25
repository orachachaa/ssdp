#include <iostream>
#include <vector>
#include <list>

// 아래 코드는 Java 스타일 코드입니다.
// => 현재 상태는 컴파일 되지 않습니다.
// => Java 반복자 사용법 설명을 위한 코드
int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// 규칙 #1. 모든 컨테이너(컬렉션)에는 iterator 멤버함수가 있어야 한다.
	// => 컨테이너의 인터페이스가 필요 하다.
	auto it1 = s.iterator();
	auto it2 = v.iterator();

	// 규칙 #2. slist 반복자와 vector 반복자는 사용법이 같아야 합니다.
	// => 모든 반복자가 지켜야하는 규칙을 인터페이스로 설계 합니다.
	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
