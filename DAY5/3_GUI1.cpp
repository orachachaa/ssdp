// 32 bit(x86)으로 설정하세요

#define USING_GUI
#include "cppmaster.h"


// 윈도우 이벤트 처리함수는 반드시 인자가 "int 4개" 이어야 합니다.
int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(foo, "A"); 
	int h2 = ec_make_window(foo, "B");

	// h2 를 h1 의 자식윈도우로 부착하기
	ec_add_child(h1, h2);

	ec_process_message();	// 프로그램을 종료 하지 말고
							// 윈도우에서 발생하는 event 를 처리해 달라는것
}

