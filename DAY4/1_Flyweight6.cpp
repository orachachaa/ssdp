#include <string>
#include <string_view>

int main()
{
	// string : ���ڿ��� ����(�� �Ҵ��� �����ؼ� ����)
	// string_view : const char* �� ����. �ܼ��� ����Ű�°�

	std::string s1 = "abcd";
	std::string s2 = s1;	// ��������(���ڿ� �ڿ��� ����)

	std::string_view sv = s1;


	// �Ʒ� 2���� �޸� ���̸� �˾ƾ� �մϴ�.
	std::string      ss1 = "abcd";
	std::string_view sv1 = "abcd";
}