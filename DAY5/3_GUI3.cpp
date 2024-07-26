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

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: on_lbutton_down(); break;
		case WM_KEYDOWN:     on_key_down(); break;
		}
		return 0;
	}

	virtual void on_lbutton_down() {}
	virtual void on_key_down() {}
};

int main()
{
	Window w;
	w.create("A");	

	ec_process_message();
}

