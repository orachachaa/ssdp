#include <stdlib.h>
// 방법 #2. Strategy 패턴
// => 변하는 것(알고리즘, 정책)을 다른 클래스로 분리
// => 컨테이너가 사용하는 메모리 할당/해지 정책을 별도의 클래스로 분리.



// 메모리 할당기의 인터페이스
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
//--------------------------------------
// 위 코드의 의도
// => 컨테이너(vector) 자체는 메모리 할당/해지 기능이 없다.
// => 별도의 메모리 할당기를 만들어서 vector 에 전달해 달라는 것

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
	vector<int> v(4, &ma );
}


