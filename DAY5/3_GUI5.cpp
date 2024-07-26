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

		ec_set_window_rect(child->handle, 30, 30, 200, 200);
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
			self->handle_lbutton_down();
			break;

		case WM_KEYDOWN:
			self->on_key_down();
			break;
		}
		return 0;
	}

	void handle_lbutton_down()
	{
		// #1. 자신이 먼저 처리를 시도
		if (on_lbutton_down() == true)
			return;

		if (parent != 0)
			parent->handle_lbutton_down();
	}

	virtual bool on_lbutton_down() { return false; }
	virtual void on_key_down() {}
};

class MainWindow : public Window
{
public:
	bool on_lbutton_down() override
	{
		std::cout << "MainWindow on_lbutton_down()\n";

		return true;
	}
};

class ImageView : public Window
{
public:
	
	bool on_lbutton_down() override
	{
		std::cout << "ImageView on_lbutton_down()\n";

//		return true; // event 처리를 종료해 달라
		return false;// event 를 부모 윈도우에도 보내 달라
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

// 대부분의 GUI 라이브러리는 
// 자식윈도우 이벤트 => 부모 윈도우에도 전달하게 됩니다.

// Chain Of Responsiblity  패턴의 응용인데
// 대부분 자신들의 용어를 사용합니다
// 
// C# WPF : Bubbling Event
// IOS cocoa touch : Responder Chain
// MFC : Command Routing