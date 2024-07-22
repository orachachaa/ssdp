// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	// 클래스 작성시, 생성자를 통해서 모든 멤버를 초기화 하는 것이 좋은 코드입니다.
	Person(const std::string& name, int age) : name(name), age(age) {}
};

// 아래 주석대로 코드 작성해 보세요.
// 1. Person 으로 부터 파생된 Student 만들어 보세요
// 2. "int id" 멤버 추가해 보세요
// 3. Student 에 생성자 추가해 보세요
// 4. main 에서 Student 의 객체 만들어 보세요


int main()
{
//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
				// 버그의 원인. 모든 객체는 초기화 되는 것이 좋습니다.
}


