// 42 page ~ 
#include <stdlib.h>

template<typename T> struct IAllocator
{
	virtual T* allocate(int size) = 0;
	virtual void deallocate(T* p, int size) = 0;
	virtual ~IAllocator() {}
};

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
	IAllocator<T>* allocator;
public:
	vector(int sz, IAllocator<T>* a) : size(sz), allocator(a)
	{
		buff = allocator->allocate(size);
	}
	~vector()
	{
		allocator->deallocate(buff, size);
	}
};

template<typename T>
class MallocAllocator : public IAllocator<T>
{
public:
	T* allocate(int size) override
	{
		return static_cast<T*>(malloc(sizeof(T) * size));
	}
	void deallocate(T* p, int size) override
	{
		free(p);
	}
};

int main()
{
	MallocAllocator<int> ma;
	vector<int> v(4, &ma);
}