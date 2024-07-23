#include <string>
#include <iostream>

// C++ ǥ�� string Ŭ������ ��Ȯ�� �̸���
// std::basic_string �Դϴ�. template �Դϴ�
// => cppreference.com ���� "std::string �˻�"

template<typename T,
		 typename Traits = std::char_traits<T>, 
		 typename Alloc = std::allocator<T>>
class basic_string
{
	T* ptr;	  // ���ڿ��� �ִ� �޸�
	Alloc ax; // �޸� �Ҵ��
public:
};




int main()
{
	std::string s1 = "abcd";
	std::string s2 = "ABCD";

	std::cout << (s1 == s2) << std::endl; 
}