// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	std::vector<Dog*>    v1;
	std::vector<Animal*>    v2;
}
