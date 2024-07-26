#define USING_GUI
#include "cppmaster.h"
#include <map>


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
			self->on_lbutton_down();
			break;

		case WM_KEYDOWN:
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
};

class ImageView : public Window
{
public:
	void on_lbutton_down() override
	{
		std::cout << "ImageView on_lbutton_down()\n";
	}
};

int main()
{
	MainWindow w;
	w.create("A");

	ImageView view;
	view.create("view");

	ec_process_message();
}

