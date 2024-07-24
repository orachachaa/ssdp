// 7_싱글톤1 - 123 page
#include <iostream>

// 오직 한개의 객체를 어떻게 만들것인가 ?
// 1. static 지역 변수
// 2. static 멤버 데이타
// 3. heap

class Cursor
{
private:
	Cursor() {	std::cout << "Cursor()\n";	}


	Cursor(const Cursor& c) = delete; 
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;  // error. 자신과 동일타입의 객체를 멤버에 넣을수 없다

	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
//		static Cursor instance;
		return instance;
	}
};

// static 멤버 데이타는 반드시 클래스 외부에 선언 필요 합니다.
Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}




