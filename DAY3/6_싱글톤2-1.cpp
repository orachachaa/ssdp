#include <iostream>

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor&) = delete;

	// C++17 inline static ����
	// => static ��� ����Ÿ ���鶧 Ŭ���� �ܺ� ������ �ʿ� �����ϴ�.
	// => visual studio ���ô� C++ ���� 17 �̻����� �����ؾ� �մϴ�.
	inline static Cursor instance; 
public:
	static Cursor& get_instance()
	{
		return instance;
	}
};



int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}




