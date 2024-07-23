// 42 page ~ 
#include <stdlib.h>

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		//buff = new T[size];
		buff = allocate(size);
	}
	~vector()
	{
		//delete[] buff;
		deallocate(buff, size);
	}
	// 메모리 할당/해지를 책임지는 가상함수
	// => vector 내부의 모든 코드에서 메모리 할당/해지가 필요하면
	//    아래 가상함수 사용
	virtual T* allocate(int size) { return new T[size]; }
	virtual void deallocate(T* p, int size) { delete[] p; }
};

template<typename T>
class MyVector : public vector<T>
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
	MyVector<int> v(4);
}





