#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>


class Window
{
	int handle;

	inline static map<int, Window*> this_map;	

	Window* parent = nullptr; // 부모 윈도우는 한개 이다.

	std::vector<Window*> child_vector; // 자식윈도우는 여러개

public:

	void add_child(Window* child)
	{
		child->parent = this;
		child_vector.push_back(child);

		// C 함수로 실제 자식윈도우로 부착
		ec_add_child(this->handle, child->handle);
	}



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

	w.add_child(&view);

	ec_process_message();
}

