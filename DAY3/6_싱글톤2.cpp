// 7_�̱���1 - 123 page
#include <iostream>

// ���� �Ѱ��� ��ü�� ��� ������ΰ� ?
// 1. static ���� ����
// 2. static ��� ����Ÿ
// 3. heap

class Cursor
{
private:
	Cursor() {	std::cout << "Cursor()\n";	}


	Cursor(const Cursor& c) = delete; 
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;  // error. �ڽŰ� ����Ÿ���� ��ü�� ����� ������ ����

	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
//		static Cursor instance;
		return instance;
	}
};

// static ��� ����Ÿ�� �ݵ�� Ŭ���� �ܺο� ���� �ʿ� �մϴ�.
Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}




