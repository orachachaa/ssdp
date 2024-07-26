#define USING_GUI
#include "cppmaster.h"
#include <map>

class WindowBase
{
protected:
	int handle;
	inline static map<int, WindowBase*> this_map;
public:
	void on_lbutton_down() {}
	void on_key_down() {}

	// 그 외 다양한 멤버
	void mode() {}
	void hide() {}
};

template<typename T>
class Window : WindowBase
{
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->on_lbutton_down();
			break;

		case WM_KEYDOWN:
			self->on_key_down();
			break;
		}
		return 0;
	}
};

class MainWindow : public Window<MainWindow>
{
public:
	void on_lbutton_down()
	{
		std::cout << "MainWindow on_lbutton_down()\n";
	}
};

int main()
{
	MainWindow w;
	w.create("A");

	ec_process_message();
}
