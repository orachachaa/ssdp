#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


// "Raw Pointer" 를 사용하지 말고
// "Raw Pointer" 의 대행자(Proxy) 를 만들어 봅시다.

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
	// calc1, calc2는 포인터가 아닌 객체입니다
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




