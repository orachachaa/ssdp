#include <vector>
#include <iostream>
#include <ranges> // C++20 ���� �߰�

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };
	
	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); // ��ø�� ����

	for (auto e : rv)
	{
		std::cout << e << std::endl;
	}

}