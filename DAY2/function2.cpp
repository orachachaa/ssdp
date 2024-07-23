// function1.cpp
// => �޴� ���� �ϼ��� ���� ���� ���� ����
#include <functional>
#include <iostream>
using namespace std::placeholders; // _1, _2, _3 ... �� ����

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

void f1(int)      {}
void f2(int, int) {}

int main()
{
	// C �Լ� �����ʹ� �������� �����ϴ�.
//	void(*f)(int);
//	f = &f1; // ok
//	f = &f2; // error. ������ ������ �ٸ��ϴ�.
	//-------------------------------------

	// std::function : �Լ������Ϳ� ������ �뵵�� ����ϱ� ����
	//					C++ ǥ�� Ŭ����
	std::function<void(int)> f;

	f = &f1; // ok
	f(10);   // f1(10) �ᱹ, �Լ� �����Ϳ� ������ ����.

	

	// �ٽ� : std::function �� std::bind �� ��ȯ ���� ���� ����

//	f = &f2; // error. f2�� ���ڰ� 2��. 

	f = std::bind(&f2, 3, _1); // ok. 2�� => 1������ ����
	f(10); // f2(3, 10)
}