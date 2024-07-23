#include <stdlib.h>
#include <memory>

// ��� #3. Policy Base Design( ���� ���� ������ )
// => Ŭ������ ����ϴ� �Ϻ� ��å�� "������ Ŭ����"�� ���� ��ü �����ϰ� �Ѵ�.
// => �׷���, ��ü ����� �������̽������ �ƴ϶�
// => ���ø� ���ڷ� ��ü �Ѵ�.!!
// => C++ ǥ�� STL �� ���� ���� ���



template<typename T>
class MallocAllocator
{
public:
	inline T* allocate(int size) {	return static_cast<T*>(malloc(sizeof(T) * size));	}
	inline void deallocate(T* p, int size) {free(p);}
};

// �ٽ� : template ���ڷ� �޸� �Ҵ���̸�(Ŭ�����̸�)�� ���� �޾Ƽ� ���

// std::allocator : C++ ǥ���� �����ϴ� �޸� �Ҵ��
//					new/delete ���
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


