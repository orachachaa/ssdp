// 7 page
#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {} // 가상 소멸자(다음 시간에...)
};
class Dog : public Animal
{
public:
	int color;
};
class Cat : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog d;

	Animal* p;
	p = &d;
	//p = &a;

	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;

	Dog* pDog2 = dynamic_cast<Dog*>(p);
	std::cout << pDog2 << std::endl;

	Cat* pCat = dynamic_cast<Cat*>(p);
	std::cout << pCat << std::endl;
}











