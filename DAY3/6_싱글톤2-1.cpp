// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

class Cursor
{
private:
	Cursor() {
		std::cout << __func__ << std::endl;
	}
	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor&) = delete;

	inline static Cursor instance;
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	std::cout << __func__ << std::endl;
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	//Cursor c3 = c1;
}








