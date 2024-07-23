#include <string>
#include <iostream>

// C++ 표준 string 클래스의 정확한 이름은
// std::basic_string 입니다. template 입니다
// => cppreference.com 에서 "std::string 검색"

template<typename T,
		 typename Traits = std::char_traits<T>, 
		 typename Alloc = std::allocator<T>>
class basic_string
{
	T* ptr;	  // 문자열이 있는 메모리
	Alloc ax; // 메모리 할당기
public:
};




int main()
{
	std::string s1 = "abcd";
	std::string s2 = "ABCD";

	std::cout << (s1 == s2) << std::endl; 
}