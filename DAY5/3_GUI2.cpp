#define USING_GUI
#include "cppmaster.h"

class CWnd
{
	int handle;
public:
	void Create()
	{
	}

	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};

class MyWindow : public CWnd
{
public:
	void LButtonDown() override { std::cout << "LBUTTON" << std::endl; }
	void KeyDown()     override { std::cout << "KEYDOWN" << std::endl; }
};

class Window
{
	int handle;
public:
	void crate(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
	}

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
	w.crate("A");

	ec_process_message();
}
