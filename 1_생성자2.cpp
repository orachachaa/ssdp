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
	Derived() { }
	Derived(int a) { }
};
int main()
{

}
