// 5번 복사해오세요
// 4번 복사해오세요..
// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"



int main()
{
	ICalc* calc1 = load_proxy();
	calc1->AddRef();
	
	ICalc* calc2 = calc1;
	calc2->AddRef();

	calc2->Release();
	std::cout << "-------------------\n";

	calc1->Release();
	std::cout << "-------------------\n";
}





