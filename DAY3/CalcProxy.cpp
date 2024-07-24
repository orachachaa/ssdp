// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

// 윈도우 에서 DLL 에서 함수를 만들때는 아래 처럼해야 합니다.
extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}

// 리눅스용 C++ 컴파일러        : g++
// visual studio 의 C++컴파일러 : cl
// => 윈도우 시작버튼누르고
// => "developer Command.... " 검색 후 실행
// => 나타나는 창에서 cl 이라고 입력해 보세요

// 현재 소스가 있는 곳으로 이동해서 아래 처럼 빌드하면 DLL 생성됩니다.

// cl CalcProxy.cpp   /LD   /link user32.lib  gdi32.lib  kernel32.lib

// /LD : DLL로 빌드하라는 옵션

// /link user32.lib  gdi32.lib  kernel32.lib : cppmaster.h 에서 IPC 기술사용하기때문에
