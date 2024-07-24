// 7_싱글톤1 - 123 page
#include <iostream>

// 오직 한개의 객체를 어떻게 만들것인가 ?
// 1. static 지역 변수
//		=> get_instance() 가 최초 호출될때 생성됨
//		=> 한번도 호출하지 않으면 생성자 호출 안됨
//		=> 늦은 초기화(lazy initialization)
//		=> thread safe ????
// 
// 2. static 멤버 데이타
//    => 결국 전역변수와 동일한 특징
//    => 프로그램 최초 실행시 생성됨(생성자 호출), main 함수 이전
//    => 한번도 사용하지 않아도 생성됨.
//    => 이른 초기화(early initialization)
//    => 프로그램 초기화시 모든 작업을 하고 싶을때 사용, 실행중에는 성능저하없게
//    => 주스레드만 있을때 생성됨. thread safe!
// 
// 3. heap

class Cursor
{
private:
	Cursor() {	std::cout << "Cursor()\n";	}


	Cursor(const Cursor& c) = delete; 
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;  // error. 자신과 동일타입의 객체를 멤버에 넣을수 없다
//	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
// static 멤버 데이타는 반드시 클래스 외부에 선언 필요 합니다.
//Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}




