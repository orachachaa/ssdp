#include <iostream>

int main()
{
	// string : ���ڿ��� ����(�� �Ҵ� �� �����ؼ� ����)
	// string_view : const char* �� ����, �ܼ��� ����Ű�� ��

	std::string s1 = "abcd";
	std::string s2 = s1; // ���� ���� (���ڿ� �ڿ��� ����0
	std::string_view sv = s1;

	std::string ss1 = "abcd";
	std::string_view sv1 = "abcd";
}