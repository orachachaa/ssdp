#include <string>
#include <iostream>

template<typename T,
	typename Traits = std::char_traits<T>,
	typename Alloc = std::allocator<T>>
class basic_string
{
	T* ptr;
	Alloc ax;
public:
	bool operator==(const std::basic_string& other)
	{
		return Traits::compare(ptr, other.ptr);
	}
};

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "ABCD";

	std::cout << (s1 == s2) << std::endl; // 0 ? 1
}

using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;
