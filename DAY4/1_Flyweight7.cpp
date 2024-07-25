#include <string>
#include <string_view>

// 인자로 받은 문자열을 읽기만 하려고 합니다(쓰기 안함)
// => 최선의 코드를 찾아 봅시다

//void f1(std::string s) {} // worst,  복사본 생성

void f2(const std::string& ss) {} // good, 단 best 는 아님.

void f3(std::string_view sv)    {} // best












int main()
{
	std::string s = "abcd";

	// 아래 경우는 f2, f3  비슷합니다.
	f2(s);
	f3(s);

	// 하지만 아래코드는 차이가 많이 있습니다.
	f2("hello");
	f3("hello");
}