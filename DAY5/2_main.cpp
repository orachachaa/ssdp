// add.h, add.cpp
// foo.h, foo.cpp
// ��� ���忡 ���� �� �ּ���

#include <iostream>
#include "add.h"
#include "foo.h"

int main()
{
	add1(1, 2);
	add2(1, 2);

	foo();	

	std::cout << "main : " << &add2 << std::endl;
}


// �ٽ� ����

// #1. inline �Լ��� ������ü�� "��� ����" �� �־�� �մϴ�

// #2. �Ϲ� �Լ��� ���� ��ü�� ����� ������ �ȵ˴ϴ�.


// #3. inline �� ��Ȯ�� �ǹ�

// 1. inline ġȯ�� �ش޶�(������ �ɼǿ� ���� �޶����� ����)

// 2. "multiple definition �� ����� �޶�"
//    => ���� ����� �������Ͽ��� �Ѱ��� �������� �����Ϸ�(��Ŀ)�� ����.
//    => cppreference.com ���� inline �˻�