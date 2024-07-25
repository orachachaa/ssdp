// 참고
class AAA
{
public:
	static int data;
	typedef int dword;
};
int AAA::data = 0;

int p = 0;

template<typename T>
void foo(T a)
{
	// 아래 코드를 보고 * 의 의미를 생각해보세요
	// => 곱하기 ? 포인터 변수 선언
//	AAA::data*  p;	// 1. AAA::data 는 "값" 따라서, * 는 곱하기 연산자
//	AAA::dword* p;	// 2. AAA::dword 는 "타입" 따라서, * 는 포인터 연산자

	// 즉, "클래스이름::이름" 에서 이름은
	// 1. 값일수도 있고
	// 2. 타입일수도 있습니다.

	// 아래 코드 해석해 보세요
	// dependent name : 템플릿 인자 T에 의존하는 이름
	//					컴파일러는 기본적으로 "값"으로 해석한다

//	T::dword* p2;		// error, 값으로 해석하므로 곱하기로 해석
						// p2를 찾을수 없다. 그래서 에러

	typename T::dword* p2; // ok
							// dependent name 을 타입으로 해석해 달라는것
}
int main()
{

}


