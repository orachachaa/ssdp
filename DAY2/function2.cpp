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
	void(*f)(int);
	f = &f1; // ok
	f = &f2; // error. ������ ������ �ٸ��ϴ�.
	//-------------------------------------
}