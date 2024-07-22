#include <iostream>

class Animal
{
public:
	// non-virtual : �⺻ ���ε�(static_binding) �ش޶�� ��
	//				"�����Ͻÿ� ������ Ÿ������ ȣ�� ����"
	void cry1() { std::cout << "Animal cry1" << std::endl; }

	// virtual : dynamic binding �ش޶�� ��
	//				"����� �޸� ������ �Լ� ����"
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	        void cry1() { std::cout << "Dog cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }
};

int main()
{
	Animal a; 
	Dog d;	  

	Animal* p = &d;

	p->cry1();	// static binding   "Animal cry1"
	p->cry2();	// dynamic binding  "Dog cry2"
}

// �������� �Ѱ� �����ϰ�, "godbolt.org" �� ������ ������
