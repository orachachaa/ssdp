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
};

int main()
{
	// calc1, calc2�� �����Ͱ� �ƴ� ��ü�Դϴ�
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;
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




