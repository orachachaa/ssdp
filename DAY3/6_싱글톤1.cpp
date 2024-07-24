// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재 하고
//		    어디에서도 동일한 방식으로 접근 가능하게 한다.

// => 결국 전역변수와 유사
// => "전역변수"는 좋지 않다고 배우게 됩니다.
// => 그래서, 싱글톤 패턴에 대한 비판도 많이 있습니다.


class Cursor
{
	// 규칙 #1. 생성자는 private 에
private:
	Cursor() {}

	// 규칙 #2. 복사 생성자와 대입연산자를 컴파일러가 만들지 못하게 한다.
	Cursor(const Cursor& c) = delete; // 함수 삭제 문법
	Cursor& operator=(const Cursor&) = delete;
									// 복사 생성자 삭제시
									// 대입도 삭제하는 것이 관례


	// 규칙 #3. 오직 한개의 객체를 생성해서 반환하는 static 멤버 함수
public:
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

//	Cursor c1, c2;
//	Cursor c3 = c1; // 복사 생성자 호출
					// 이렇게 만드는 것도 막아야 합니다.
}








