#define USING_GUI
#include "cppmaster.h"



//------------------------
class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
	}

	// 이번 단계의 핵심
	// => 아래 멤버 함수가 static 일수 밖에 없는 이유를 알아야 합니다.
	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.create("A");	// 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();	
}

