#include <iostream>

// 규칙 #1. 기반 클래스 소멸자는 되도록 가상함수로 하세요

// 그런데, 가상함수를 사용하면, "가상함수 테이블"등이 메모리에 놓여서 
// 오버헤드가 있습니다.

// 클래스에 다른 가상함수가 없고, Base* p 인 상태로 "delete p" 하는 코드를 
// 사용하지 않을것이라면 오버헤드를 없애고, 안전하게 하기 위해
// 소멸자를 "protected" 에 만드세요

class Base
{
	// protected 생성자 의도 : Base* 인 상태로는 delete 하지 못하게 하기 위해
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived;
	delete p;	// Base::~Base() 호출해야 하는데, protected 이므로 error.

	Derived* p2 = new Derived;
	delete p2;  // 1. Derived::~Derived() 이므로 ok
			    // 2. Base::~Base() 도 호출되는데, ~Derived() 안에서 호출되므로
				//							protected 라도 접근 가능.

}
