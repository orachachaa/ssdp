// function1.cpp
// => �޴� ���� �ϼ��� ���� ���� ���� ����
#include <functional>
#include <iostream>
using namespace std::placeholders; // _1, _2, _3 ... �� ����

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);  // foo�� 4�� �Լ�

	// std::bind : ���ڸ� ������ ���ο� �Լ��� ����� ����
	
	// ����     : std::bind(M���Լ��ּ�, M������)

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // 4�� => 0�� �Լ��� ����
	f1();

	auto f2 = std::bind(&foo, 10, _1, 3, _2); // 4�� => 2��
	f2(5, 9); // foo(10, 5, 3, 9)


	auto f3 = std::bind(&foo, 3 , _3 , _2 , _1 ); 

	f3(9, 4, 7); // foo(3, 7, 9, 4) �� �ǵ��� �� ? ä�켼��

	// ���� : std::bind �� ��ȯ Ÿ����, ������ ���¿� ����
	//	     ��� �ٸ� Ÿ���Դϴ�. �׷��� auto �� �޾ҽ��ϴ�.
}