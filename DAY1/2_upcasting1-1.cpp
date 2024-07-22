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

//	Animal* p = &d;
	Animal* p = &a;

	// static_cast : �����Ϸ����� Dog* ó�� ������ �޶�� ��û�ϴ� ��
	//			     ������ �ð��� ����, ������� ����.
	//			     ��ü�� ���� Dog ����, �����Ϸ��� �����Ҽ� ����. 
	//			     ��, ��ü�� Dog �� �ƴ϶� ����. 
	//				 Dog ��ü�� �ƴ϶�� �����ڰ� å������ �մϴ�.
	Dog* pdog = static_cast<Dog*>(p);

	std::cout << pdog << std::endl; 

	if (pdog != nullptr)
	{
//		pdog->color = 10;	// ����!!!!
							// pdog �� 0 �� �ƴ����� Dog �� �ƴ� Animal ��ü
							// �߸��� �ڵ�, ������ å��
							// Ȯ���� �������� static_cast ����ؾ� �մϴ�
	}

	// #2. dynamic_cast : ����ð� ĳ����
	//					  �����Ҷ�, p�� ����Ű�� ���� Dog ���� ������ ĳ����
	//					  Dog ��ü�� �ƴ� ��� 0 ��ȯ
	Dog* pdog2 = dynamic_cast<Dog*>(p);

	std::cout << pdog2 << std::endl;
}











