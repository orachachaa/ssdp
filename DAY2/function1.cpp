// function1.cpp
// => �޴� ���� �ϼ��� ���� ���� ���� ����
#include <functional>
#include <iostream>

void foo(int a, int b int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);  // foo�� 4�� �Լ�

	// std::bind : ���ڸ� ������ ���ο� �Լ��� ����� ����
	
	// ����     : std::bind(M���Լ��ּ�, M������)

	auto f1 = std::bind(&foo, 1, 2, 3, 4);
	f1();

}