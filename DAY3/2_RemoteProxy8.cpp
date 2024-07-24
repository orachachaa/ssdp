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

	// Raw Pointer 처럼 사용할수 있도록 하기 위해서 -> 와 * 연산자 재정의
	// => 스마트 포인터의 핵심!!
	// => 스마트 포인터는 결국 "smart proxy" 입니다
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	// calc1, calc2는 포인터가 아닌 객체입니다
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;

	// calc1, calc2 는 "객체"지만 "포인터의도로 사용하므로"
	// -> 와 * 가 되어야 합니다.

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




