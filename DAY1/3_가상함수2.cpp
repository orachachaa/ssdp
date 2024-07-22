#include <iostream>

class Base
{
public:
//	~Base() {}
	virtual ~Base() {} // 핵심 : 클래스가 기반 클래스로 사용된다면
					   //        소멸자를 반드시 "virtual" 로 해야 합니다.
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d; // ok. 아무 문제 없음.


//	Derived* p = new Derived;
//	delete p;	// ok. 아무 문제 없음.


	Base* p = new Derived;
	delete p;	// ???

	// 소멸자 호출도 함수 호출입니다.
	// => static binding 할지, dynamic binding 할지 결정해야 합니다

	// 1. 컴파일러는 p 가 " Base* " 라는 것만 알고 있습니다.
	// 2. 따라서, Base 클래스 선언을 보고 소멸자가 "virtual" 인지 아닌지 조사합니다.

	// virtual 이 아니면 : static binding 이므로 Base::~Base() 호출!
	// virtual 이면      : dynamic binding 이므로 "메모리 조사후" 결정
}	
