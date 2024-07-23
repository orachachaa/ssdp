#include <string>
#include <iostream>

// C++ ǥ�� string Ŭ������ ��Ȯ�� �̸���
// std::basic_string �Դϴ�. template �Դϴ�
// => cppreference.com ���� "std::string �˻�"

template<typename T,		// Ansi, unicode
		 typename Traits = std::char_traits<T>, // ���ڿ� ����å Ŭ����
		 typename Alloc = std::allocator<T>>
class basic_string
{
	T* ptr;	  // ���ڿ��� �ִ� �޸�
	Alloc ax; // �޸� �Ҵ��
public:
	bool operator==(const std::basic_string& other)
	{
		// �ᱹ ���ڿ� �񱳴� �������� �ʰ�
		// �� ��å Ŭ������ static ��� �Լ��� ����մϴ�.
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