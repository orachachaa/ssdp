#include <string>
#include <string_view>

// ���ڷ� ���� ���ڿ��� �б⸸ �Ϸ��� �մϴ�(���� ����)
// => �ּ��� �ڵ带 ã�� ���ô�

void f1(std::string s) {}

int main()
{
	std::string s = "abcd";

	f2(s);
	f3(s);
}