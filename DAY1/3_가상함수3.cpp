// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
// 가상함수 관련 간단한 문법 정리
class Derived : public Base
{
public:
	// #1. 가상함수 override 시에는 "virtual" 없어도 됩니다.
//	virtual void foo() {}
//	void foo() {}			// ok 위 코드와 완전히 동일

	// #2. 가상함수 override 시에 실수(오타) 가 있어도
	// => 에러 아닙니다.
	// => 다른 가상함수를 추가한 것으로 해석
//	virtual void fooo() {}		// ok
//	virtual void goo(double){}	// ok

	// #3. 위 사실에 수많은 버그의 원인이 되었습니다.
	// => 그래서, C++11 에서 "override" 키워드 도입
	// => override 사용시 "virtual" 을 붙이지 않아도 가독성이 나쁘지 않습니다.
	virtual void fooo() override {}  // error. 
		
			
};

int main()
{
}





