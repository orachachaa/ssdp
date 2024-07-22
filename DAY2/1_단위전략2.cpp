#include <stdlib.h>

// ��� #1. template method 
// => ���ϴ� ��(�޸� �Ҵ�/���� ���) �� �����Լ��� �и�

// ���� : �޸� �Ҵ�/���� ��å�� MyVector �� ���ԵǾ� �ִ�.
// vector �� �ƴ϶�, list, set, map �� �޸� �Ҵ� ����� �����ϰ� �ʹٸ�
// => ���� �Ļ� Ŭ������ ���� ���� �����ؾ� �Ѵ�
// => �޸� �Ҵ� ��å�� ������ �����̳ʰ� ���� �Ҽ� ����!

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
//		buff = new T[size];
		buff = allocate(size);
	}
	~vector()
	{
//		delete[] buff;		
		deallocate(buff, size);
	}

	// �޸� �Ҵ�/������ å������ �����Լ�
	// => vector ������ ��� �ڵ忡�� �޸� �Ҵ�/������ �ʿ��ϸ�
	//    �Ʒ� �����Լ� ���
	virtual T* allocate(int size) { return new T[size]; }
	virtual void deallocate(T* p, int size) { delete[] p; }
};

// �� �ڵ��� �ǵ�
// => �޸� �Ҵ�/���� ����� �����Ϸ��� �Ļ� Ŭ������ ����
//    ��ӵ� �����Լ��� override �ϸ� �ȴ�.

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


