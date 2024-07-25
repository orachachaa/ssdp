#include <iostream>

void f1(std::string s) {} // worst
void f2(const std::string& s) {} // good
void f3(std::string_view sv) {} // best

int main()
{
	std::string s = "abcd";

	f1(s);

	// 아래 경우는 f2, f3 모두 비슷
	f2(s);
	f3(s);

	f2("hello");
	f3("hello");
}