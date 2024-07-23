#include <stdlib.h>

// 방법 #3.


// 실행시간에 다른 할당기로 교체 하려면 "약한 결합"이  되어야 한다.
// 그런데, 인터페이스를 만들면 "가상함수" 일수 밖에 없다.

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


