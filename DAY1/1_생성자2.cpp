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
	// �Ʒ� �ڵ尡 �� �������� ������ ������
	Derived() : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{
	Derived d1;
	Derived d2(10);
}
