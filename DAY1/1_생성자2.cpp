#include <iostream>

class Base
{
public:
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 아래 코드가 왜 에러인지 생각해 보세요
	// => 핵심 : Base 에 디폴트 생성자가 없다는 점. 
	// => 그런데, 컴파일러는 오른쪽 주석 처럼 변경..
	//    따라서, 17, 18 줄에서 에러발생. "Base()" 가 없다는 에러
//	Derived()      {} // Derived()      : Base() {} 
//	Derived(int a) {} // Derived(int a) : Base() {}

	// 해결책
	// => 기반 클래스에 디폴트 생성자가 없다면
	// => 파생 클래스 제작자는 반드시 명시적으로 기반클래스의 다른 생성자를 
	//    호출해야 합니다.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{

}

// C++ 등의 객체지향 언어는 "컴파일러가 추가" 하는 코드가 아주 많이 있습니다.
// => 편리할수도 있지만
// => 정확히 모르면 버그의 원인 이 되기도 합니다.

// "Zig" 언어
// => "보이는 것만 실행된다"
// => "컴파일러가 추가하는 것은 없다" 라는 모토로 등장한 언어. 