#include <string>
#include <string_view>

int main()
{
	// string : 문자열을 소유(힙 할당후 복사해서 소유)
	// string_view : const char* 와 동일. 단순히 가리키는것

	std::string s1 = "abcd";
	std::string s2 = s1;	// 깊은복사(문자열 자원을 복사)

	std::string_view sv = s1;


	// 아래 2줄의 메모리 차이를 알아야 합니다.
	std::string      ss1 = "abcd";
	std::string_view sv1 = "abcd";
}