#include <iostream>

// C++ ���� : �����ڿ��� �����Լ��� �������� �ʴ´�.
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
// ���ڵ� ������ ������ ������
