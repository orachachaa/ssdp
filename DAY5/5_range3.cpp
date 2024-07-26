#include <vector>
#include <iostream>

template<typename T>
class take_view
{
	T& r;
	int cnt;
public:
	take_view(T& r, int c) : r(r), cnt(c) {}

	auto begin() { return r.begin(); }
	auto end()   { return r.begin() + cnt; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

//	take_view<std::vector<int>> tv(v, 3);
	take_view tv(v, 3);

//	for (auto e : v) 
	for (auto e : tv)
	{
		std::cout << e << std::endl;
	}

}