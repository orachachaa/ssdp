// 2_upcasting1-1.cpp
#include <iostream>

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog    d;

	Animal* p = &d;

	// static_cast : 컴파일러에게 Dog* 처럼 생각해 달라고 요청하는 것
	//			     컴파일 시간에 동작, 오버헤드 없음.
	//			     단, 객체가 Dog 가 아니라도 성공. 
	//				 Dog 객체가 아니라면 개발자가 책임져야 합니다.
	Dog* pdog = static_cast<Dog*>(p);

	std::cout << pdog << std::endl;

}











