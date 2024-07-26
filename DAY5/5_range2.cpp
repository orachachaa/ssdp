// 5_range1.cpp
#include <vector>
#include <iostream>

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;
};


int main()
{
	Point3D pt;

	for (auto e : pt) // ?
	{
		std::cout << e << std::endl;
	}

}