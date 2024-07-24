#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


// "Raw Pointer" �� ������� ����
// "Raw Pointer" �� ������(Proxy) �� ����� ���ô�.

template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }

	~sp() 
	{
		if (obj != nullptr)
			obj->Release();
	}

	// Raw Pointer ó�� ����Ҽ� �ֵ��� �ϱ� ���ؼ� -> �� * ������ ������
	// => ����Ʈ �������� �ٽ�!!
	// => ����Ʈ �����ʹ� �ᱹ "smart proxy" �Դϴ�
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	// calc1, calc2�� �����Ͱ� �ƴ� ��ü�Դϴ�
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;

	// calc1, calc2 �� "��ü"���� "�������ǵ��� ����ϹǷ�"
	// -> �� * �� �Ǿ�� �մϴ�.

	int n1 = calc1->Add(1, 2);
	int n2 = (*calc2).Add(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
	
}



/*
int main()
{
	ICalc* calc1 = load_proxy();
	calc1->AddRef(); 

	ICalc* calc2 = calc1;
	calc2->AddRef();

	calc2->Release();
	calc1->Release();	
}
*/




