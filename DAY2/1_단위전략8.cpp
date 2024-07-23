#include <string>
#include <iostream>

// C++ 표준 string 클래스의 정확한 이름은
// std::basic_string 입니다. template 입니다
// => cppreference.com 에서 "std::string 검색"

template<typename T,		// Ansi, unicode
		 typename Traits = std::char_traits<T>, // 문자열 비교정책 클래스
		 typename Alloc = std::allocator<T>>
class basic_string
{
	T* ptr;	  // 문자열이 있는 메모리
	Alloc ax; // 메모리 할당기
public:
	bool operator==(const std::basic_string& other)
	{
		// 결국 문자열 비교는 직접하지 않고
		// 비교 정책 클래스의 static 멤버 함수를 사용합니다.
		return Traits::compare(ptr, other.ptr);
	}
};

using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;





int main()
{
	std::string s1 = "abcd";
	std::string s2 = "ABCD";

	std::cout << (s1 == s2) << std::endl; 
}