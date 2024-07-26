#include <vector>
#include <iostream>
#include <ranges> // C++20 부터 추가

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };
	
	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); // 중첩도 가능

	for (auto e : rv)
	{
		std::cout << e << std::endl;
	}

}