// 2_upcasting1-1.cpp
#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {}  // ���� �Ҹ���(�����ð��� ����)
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
//	Animal* p = &a;

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

	// ��, dynamic_cast �� ����Ϸ��� "�ݵ�� 1�� �̻��� �����Լ�" �� �־�� �մϴ�.
	// => Ÿ���� ������ "�����Լ����̺�"�� �����ϹǷ�
	// => �����Լ��� �ִ� Ÿ���� "��������(polymorphic type)" �̶�� �մϴ�.
	// => ���������� ����� ����ϸ� ���� ��κ� "1���̻��� �����Լ�"�� �ְԵ˴ϴ�.
	//    (���� �Ҹ��� ������)
	Dog* pdog2 = dynamic_cast<Dog*>(p);

	std::cout << pdog2 << std::endl;

	// dynamic_cast �� "����ð� ����" �̹Ƿ� �������ϰ� �ֽ��ϴ�.
	// ���α׷� ���߽� p�� ����Ű�� ���� Dog ��� Ȯ���� ������
	// static_cast ���ϼ���

	// Ȯ���� ���ٸ� "dynamic_cast" �� �����ص� ������
	// => dynamic_cast �� ����ϸ� ���� ������ �Դϴ�.
	// => ������ ��ü�� �����ؾ� �մϴ�. ������ �ٽ� ����
}











