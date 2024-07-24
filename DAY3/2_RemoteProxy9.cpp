#include <memory>
#include "ICalc.h"

int main()
{
	// C++ 표준에 이미 스마트 포인터가 있는데!!!
	// 표준의 스마트 포인터 사용하면 안되나요 ??
	// 왜 ? sp 를 만들어야 하나요 ??

	std::shared_ptr<int> p1(new int);
						// 할당된 메모리 주소를 p1이 내부적으로 보관
						// p1 의 소멸자에서 보관하고 있던 주소를
						// "delete" 합니다.

	std::shared_ptr<ICalc> p2( load_proxy() );
						// 이코드는 결국 DLL 에서 "new" 한것을
						// 실행파일(p2의 소멸자 코드) 에서 delete 한것

	// 우리가 필요한것은 소멸자에서 "delete"가 아니라
	// "Release()" 를 호출하고 싶었던것

	// 위와 같은 이유로
	// => C++ 표준에 스마트 포인터가 있지만
	// => 많은 오픈소스가 자신들만의 스마트 포인터 제공
	// => 안드로이드 소스에도 "sp" 가 있습니다.
}