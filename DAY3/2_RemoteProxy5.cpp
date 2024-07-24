#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// 현재 단계까지 정리하면
// => 클라이언트의 코드는 아래 처럼 사용하면 됩니다.

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





