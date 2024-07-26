#include <vector>
#include <iostream>
#include <ranges> // C++20 ���� �߰�

/*
take_view operator | (vector, take(3)�ǹ�ȯŸ��)
{
	return take_view(v, take(3)��ȯŸ�Ծȿ��ִ� 3�̶�� ���� ������)
}
*/
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); 

	// �Ʒ� ������ �� 2�ٰ� ������ �����մϴ�.
	
	auto rv2 = v | std::views::take(3) | std::views::reverse;


//	for (auto e : rv)
	for (auto e : rv2)
	{
		std::cout << e << std::endl;
	}

}