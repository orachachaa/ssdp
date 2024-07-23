#include <iostream>
#include <vector>

template<typename T>
class debug_alloc
{
public:
	inline T* allocate(std::size_t size)
	{
		T* p = static_cast<T*>(malloc(sizeof(T) * size));
		printf("allocate : %p, %zd\n", p, size);
		return p;
	}
	inline void deallocate(T* p, std::size_t size)
	{
		printf("deallocate : %p, %zd\n", p, size);
		free(p);
	}

	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
	using value_type = T;
};

int main()
{
	//std::vector<int> v;
	std::vector<int, debug_alloc<int>> v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;
}
