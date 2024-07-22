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
	Derived() : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{
	Derived d1;
	Derived d2(10);
}
