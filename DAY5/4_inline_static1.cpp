// 4_inline_static1

// Sample.h
class Sample
{
public:
	void foo();

	// �Ʒ� �ڵ�� definition �� �ƴմϴ�.
	// declaration �Դϴ�.
	// �Ϲ� ���������� "extern int data" �ǹ�
	static int data;
};


// Sample.cpp
#include "Sample.h"

// static ��� ����Ÿ�� "�ᱹ �������� �Դϴ�."
// => �ҽ��� "definition" �� �־�� �մϴ�.
int Sample::data = 0;  

void Sample::foo() 
{
}