#include <vector>
#include <iostream>
#include <ranges> // C++20 부터 추가

/*
take_view operator | (vector, take(3)의반환타입)
{
	return take_view(v, take(3)반환타입안에있는 3이라는 정보 꺼내기)
}
*/
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); 

	// 아래 한줄이 위 2줄과 완전히 동일합니다.
	
	auto rv2 = v | std::views::take(3) | std::views::reverse;


//	for (auto e : rv)
	for (auto e : rv2)
	{
		std::cout << e << std::endl;
	}

}