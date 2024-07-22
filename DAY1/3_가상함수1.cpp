#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// override : 기반 클래스 멤버함수를 파생 클래스가 다시 구현하는 것
	// overloading 과 헷갈리지 마세요 : square(int), square(double)
	void cry() { std::cout << "Dog cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry(); // Animal Cry
	Dog d;	  d.cry(); // Dog Cry

	Animal* p = &d; 

	p->cry();	// 객체는 Dog, 포인터 타입은 Animal*
				// 어떤 함수가 호출될까요 ?
				// 어떤 함수를 호출하는게 논리적으로 맞을까요 ?
}



