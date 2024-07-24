#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy(); // 이 코드는 결국
								// 1. DLL 내부의 create() 를 호출하게됩니다.
								// 2. "new Calc" 로 Proxy 생성
								// 사용후에 delete 해야 되지 않을까요 ?

	delete calc; // 이렇게 해도 안전할까요 ??

	// .dll 과 .exe 는 각각 다른 컴파일러를 사용하게 될수도 있습니다.
	// 따라서
	// .dll 에서 할당한 자원은 .dll 에서 해지 되어야 합니다.
	// => 자원의 할당과 해지는 "같은 모듈"에서 해야 합니다.

}





