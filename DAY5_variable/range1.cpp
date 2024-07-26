#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	for (auto e : v)
	{
		std::cout << e << std::endl;
	}

	// 위 for문의 원리
	auto first = v.begin();
	auto last = v.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		// 여기부터 사용자 코드
	}
}