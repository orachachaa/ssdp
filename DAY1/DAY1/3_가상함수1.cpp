#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// override : 기반 클래스 멤버함수를 파생 클래스가 다시 구현하는 것
	// overloading 과 헷갈리지 마세요 : square(int), square(double)
	void cry() { std::cout << "Dog cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry(); // Animal Cry
	Dog d;	  d.cry(); // Dog Cry

	Animal* p = &d; 

	p->cry();	// 객체는 Dog, 포인터 타입은 Animal*
				// 어떤 함수가 호출될까요 ?
				// 어떤 함수를 호출하는게 논리적으로 맞을까요 ?
}

// p->cry() 를 어떤 함수와 연결할것인가 ? 
// => 함수 바인딩(function binding) 이라고 합니다.
// => 2가지 방식이 있습니다.


// 1. static binding : 컴파일 시간에 컴파일러가 결정
//					   => 핵심 : 컴파일러는 p가 가리키는 곳의 객체가 어떤 타입인지 알수 없다.
//					   => if (사용자입력 == 1 ) p = &a; 같은 코드가 있을수 있다
//					   => 컴파일러가 알고 있는 유일한 정보는 p 자체는 "Animal*" 라는것
//					   그래서, Animal cry 호출
// 논리적이지 않지만 빠르다.
// C++, C# 의 기본 정책


// 2. dynamic binding : 컴파일시에는 p가 가리키는 메모리를 조사하는 기계어 코드 생성
//						실행시에 메모리를 조사해서 함수 호출을 결정
//						p 가 Dog 객체를  가리켰다면 "Dog cry" 호출
// 논리적이지만 느리다.
// Java, Swift, Python, Kotlin, Objective-c 등의 대부분의 객체지향 언어.
// C++/C# 의 virtual function