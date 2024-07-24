#include <iostream>

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor&) = delete;

	// C++17 inline static 문법
	// => static 멤버 데이타 만들때 클래스 외부 선언이 필요 없습니다.
	// => visual studio 사용시는 C++ 버전 17 이상으로 설정해야 합니다.
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




