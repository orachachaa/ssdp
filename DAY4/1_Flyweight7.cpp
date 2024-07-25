#include <string>
#include <string_view>

// 인자로 받은 문자열을 읽기만 하려고 합니다(쓰기 안함)
// => 최선의 코드를 찾아 봅시다

void f1(std::string s) {}

int main()
{
	std::string s = "abcd";

	f2(s);
	f3(s);
}