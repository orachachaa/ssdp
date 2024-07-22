#include <iostream>

// ��Ģ #1. ��� Ŭ���� �Ҹ��ڴ� �ǵ��� �����Լ��� �ϼ���

// �׷���, �����Լ��� ����ϸ�, "�����Լ� ���̺�"���� �޸𸮿� ������ 
// ������尡 �ֽ��ϴ�.

// Ŭ������ �ٸ� �����Լ��� ����, Base* p �� ���·� "delete p" �ϴ� �ڵ带 
// ������� �������̶�� ������带 ���ְ�, �����ϰ� �ϱ� ����
// �Ҹ��ڸ� "protected" �� ���弼��

class Base
{
	// protected ������ �ǵ� : Base* �� ���·δ� delete ���� ���ϰ� �ϱ� ����
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived;
	delete p;	// Base::~Base() ȣ���ؾ� �ϴµ�, protected �̹Ƿ� error.

	Derived* p2 = new Derived;
	delete p2;  // 1. Derived::~Derived() �̹Ƿ� ok
			    // 2. Base::~Base() �� ȣ��Ǵµ�, ~Derived() �ȿ��� ȣ��ǹǷ�
				//							protected �� ���� ����.

}
