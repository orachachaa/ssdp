#include <vector>
#include <iostream>
#include <ranges> // C++20 부터 추가

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); 

	// 아래 한줄이 위 2줄과 완전히 동일합니다.
	
	auto rv2 = v | std::views::take(3) | std::views::reverse;


	for (auto e : rv)
	{
		std::cout << e << std::endl;
	}

}