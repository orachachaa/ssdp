#include <vector>
#include <iostream>
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	auto r = v | std::views::filter([](int n) { return n % 2 == 0;})
		| std::views::take(3)
		| std::views::reverse
		| std::views::enumerate; // C++23

	for (auto [id, value] : r)
	{
		std::cout << id << " : " << value << std::endl;
	}
}