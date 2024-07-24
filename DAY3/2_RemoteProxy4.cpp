#define USING_GUI
#include "cppmaster.h"


// #1. 클라이언트 제작자는 서버 제작자에게 아래 2개의 파일을  받아야 합니다
// ICalc.h        : 인터페이스가 있는 파일
// CalcProxy.dll  : Proxy 가 있는 동적 모듈
// 

// #2. dll 을 load 해서 Proxy 를 생성해서 사용하면 됩니다.
#include "ICalc.h"

ICalc* load_proxy()
{

}



int main()
{
	ICalc* calc = create();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





