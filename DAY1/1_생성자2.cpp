#include <iostream>

class Base
{
public:
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// �Ʒ� �ڵ尡 �� �������� ������ ������
	// => �ٽ� : Base �� ����Ʈ �����ڰ� ���ٴ� ��. 
	// => �׷���, �����Ϸ��� ������ �ּ� ó�� ����..
	//    ����, 17, 18 �ٿ��� �����߻�. "Base()" �� ���ٴ� ����
//	Derived()      {} // Derived()      : Base() {} 
//	Derived(int a) {} // Derived(int a) : Base() {}

	// �ذ�å
	// => ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ�
	// => �Ļ� Ŭ���� �����ڴ� �ݵ�� ��������� ���Ŭ������ �ٸ� �����ڸ� 
	//    ȣ���ؾ� �մϴ�.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{

}
