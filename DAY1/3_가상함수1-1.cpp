#include <iostream>

class Animal
{
public:
	// non-virtual : 기본 바인딩(static_binding) 해달라는 것
	//				"컴파일시에 포인터 타입으로 호출 결정"
	void cry1() { std::cout << "Animal cry1" << std::endl; }

	// virtual : dynamic binding 해달라는 것
	//				"실행시 메모리 조사후 함수 결정"
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

// 웹브라우져 한개 실행하고, "godbolt.org" 에 접속해 보세요
