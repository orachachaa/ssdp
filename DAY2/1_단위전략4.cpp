// 42 page ~ 
#include <stdlib.h>

template<typename T>
class MallocAllocator
{
public:
	inline T* allocate(int size)
	{
		return static_cast<T*>(malloc(sizeof(T) * size));
	}
	inline void deallocate(T* p, int size)
	{
		free(p);
	}
};

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
	MallocAllocator<T> allocator;
public:
	vector(int sz) : size(sz)
	{
		buff = allocator.allocate(size);
	}
	~vector()
	{
		allocator.deallocate(buff, size);
	}
};

int main()
{
	vector<int> v(4);
}