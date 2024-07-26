#define USING_GUI
#include "cppmaster.h"
#include <map>

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

	inline static map<int, Window*> this_map;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			//on_lbutton_down();
			self->on_lbutton_down();
			break;
		case WM_KEYDOWN:
			//on_key_down();
			self->on_key_down();
			break;
		}
		return 0;
	}

	virtual void on_lbutton_down() {}
	virtual void on_key_down() {}
};

class MainWindow : public Window
{
public:
	void on_lbutton_down() override
	{
		std::cout << "MainWindow on_lbutton_down()\n";
	}

	void on_key_down() override
	{
		std::cout << "MainWindow on_key_down()\n";
	}
};

int main()
{
	MainWindow w;
	w.create("A");

	ec_process_message();
}
