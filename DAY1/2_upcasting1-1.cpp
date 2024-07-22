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

	// static_cast : �����Ϸ����� Dog* ó�� ������ �޶�� ��û�ϴ� ��
	//			     ������ �ð��� ����, ������� ����.
	//			     ��, ��ü�� Dog �� �ƴ϶� ����. 
	//				 Dog ��ü�� �ƴ϶�� �����ڰ� å������ �մϴ�.
	Dog* pdog = static_cast<Dog*>(p);

	std::cout << pdog << std::endl;

}











