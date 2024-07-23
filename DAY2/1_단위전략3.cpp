#include <stdlib.h>
// 방법 #2. Strategy 패턴
// => 변하는 것(알고리즘, 정책)을 다른 클래스로 분리
// => 컨테이너가 사용하는 메모리 할당/해지 정책을 별도의 클래스로 분리.

// 특징 : 컨테이너 자체 기능과 메모리 할당/해지 기능이 완전히 분리되어 있다.
// => 다른 컨테이너(list, set, map 등) 에서도 할당기를 사용할수 있다.

// 그런데... C++ 진영에서는 이방식의 단점으로!!!
// => 메모리 할당/해지 함수가 "가상함수" 이다.
// => 가상함수는 약간의 성능 지연과, "가상함수 테이블" 때문에 메모리 오버헤드가 있다


// 일반적인 프로그램에서 가끔 호출되는 함수는
// => 가상함수로 해도 전혀 문제 없습니다.

// 하지만, 루프안에서 수천 ~ 수만번 호출되는 함수 이거나
// STL 같은 표준 라이브러리 라면 "최고의 성능"을 낼수 있어야 합니다.




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


