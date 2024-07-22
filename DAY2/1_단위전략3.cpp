// ��� #2. Strategy ����
// => ���ϴ� ��(�˰���, ��å)�� �ٸ� Ŭ������ �и�
// => �����̳ʰ� ����ϴ� �޸� �Ҵ�/���� ��å�� ������ Ŭ������ �и�.



// �޸� �Ҵ���� �������̽�
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
// �� �ڵ��� �ǵ�
// => �����̳�(vector) ��ü�� �޸� �Ҵ�/���� ����� ����.
// => ������ �޸� �Ҵ�⸦ ���� vector �� ������ �޶�� ��

template<typename T> 
class MallocAllocator : public IAllocator<T>
{
public:
	// 2������ allocate, deallocate ������ ������.
};


int main()
{
	vector<int> v(4);
}


