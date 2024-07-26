// 5_range1.cpp

#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	for (auto e : v)
	{
		std::cout << e << std::endl;
	}
}