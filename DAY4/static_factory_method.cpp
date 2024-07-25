#include <iostream>

// C++ 문법 : 생성자에는 가상함수가 동작하지 않는다.
//	
class Base
{
public:
	Base()
	{
		init();
	}
	virtual void init() { std::cout << "Base init\n"; }	// 1
};
class Derived : public Base
{
public:
	void init() override { std::cout << "Derived init\n"; }	// 2
};
int main()
{
	Derived d; 
}
// 위코드 실행결과 예측해 보세요
