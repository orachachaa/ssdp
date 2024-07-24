// 6_싱글톤7  1번복사
#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:

	// 아래 코드는 C++11 이후 부터는 멀티스레드 환경에서 안전합니다.
	// => 동기화 됩니다.
	// => 동기화 방법 "spin lock" 
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




