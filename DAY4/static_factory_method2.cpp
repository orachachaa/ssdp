#include <iostream>

// ��ü�� ������������ �����Լ��� ȣ���ϰ� �ʹٸ�
// "static factory method" �� ����ϼ���

class Base
{
public:
	Base(){	}

	template<typename T>
	static T* create()
	{
		T* p = new T;	// ���� �����ϰ�
		p->init();		// �����Լ� ȣ�� �ϹǷ�
						// �����Լ��� ����� ����!!
						// => �����ڿ��� ȣ���Ѱ��� �ƴ�.
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
// ���ڵ� ������ ������ ������
