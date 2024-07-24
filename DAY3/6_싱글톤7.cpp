// 6_�̱���7  1������
#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:

	// �Ʒ� �ڵ�� C++11 ���� ���ʹ� ��Ƽ������ ȯ�濡�� �����մϴ�.
	// => ����ȭ �˴ϴ�.
	// => ����ȭ ��� "spin lock" 
	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}




