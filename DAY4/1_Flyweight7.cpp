#include <string>
#include <string_view>

// ���ڷ� ���� ���ڿ��� �б⸸ �Ϸ��� �մϴ�(���� ����)
// => �ּ��� �ڵ带 ã�� ���ô�

//void f1(std::string s) {} // worst,  ���纻 ����

void f2(const std::string& ss) {} // good, �� best �� �ƴ�.

void f3(std::string_view sv)    {} // best












int main()
{
	std::string s = "abcd";

	// �Ʒ� ���� f2, f3  ����մϴ�.
	f2(s);
	f3(s);

	// ������ �Ʒ��ڵ�� ���̰� ���� �ֽ��ϴ�.
	f2("hello");
	f3("hello");
}