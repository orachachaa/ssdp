#include <iostream>

int main()
{
	// string : 문자열을 소유(힙 할당 후 복사해서 소유)
	// string_view : const char* 와 동일, 단순히 가리키는 것

	std::string s1 = "abcd";
	std::string s2 = s1; // 깊은 복사 (문자열 자원을 복사0
	std::string_view sv = s1;

	std::string ss1 = "abcd";
	std::string_view sv1 = "abcd";
}