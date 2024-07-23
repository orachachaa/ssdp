#include <stdlib.h>
#include <memory>

// 방법 #3. Policy Base Design( 단위 전략 디자인 )
// => 클래스가 사용하는 일부 정책을 "별도의 클래스"로 만들어서 교체 가능하게 한다.
// => 그런데, 교체 방법이 인터페이스기반이 아니라
// => 템플릿 인자로 교체 한다.!!
// => C++ 표준 STL 이 가진 설계 방식



template<typename T>
class MallocAllocator
{
public:
	inline T* allocate(int size) {	return static_cast<T*>(malloc(sizeof(T) * size));	}
	inline void deallocate(T* p, int size) {free(p);}
};

// 핵심 : template 인자로 메모리 할당기이름(클래스이름)을 전달 받아서 사용

// std::allocator : C++ 표준이 제공하는 메모리 할당기
//					new/delete 사용
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;
	Alloc allocator;
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
//	vector<int, MallocAllocator<int> > v(4);
	vector<int > v(4);
}


