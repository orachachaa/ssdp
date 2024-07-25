#include <iostream>

class Base
{
public:
	Base()
	{
		init();
	}
	virtual void init() { std::cout << "Base init\n"; }
};
class Derived : public Base
{
public:
	void init() override { std::cout << "Derived init\n"; }
};
int main()
{
	Derived d; 
}
// 위코드 실행결과 예측해 보세요
