#include <iostream>

// 객체의 생성과정에서 가상함수를 호출하고 싶다면
// "static factory method" 를 사용하세요

class Base
{
public:
	Base(){	}

	template<typename T>
	static T* create()
	{
		T* p = new T;	// 먼저 생성하고
		p->init();		// 가상함수 호출 하므로
						// 가상함수는 제대로 동작!!
						// => 생성자에서 호출한것이 아님.
		return p;
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
	Base* p = Base::create<Derived>();
}
// 위코드 실행결과 예측해 보세요
