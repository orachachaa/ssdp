#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>


class Window
{
	int handle;

	inline static map<int, Window*> this_map;

	Window* parent = nullptr; // �θ� ������� �Ѱ� �̴�.

	std::vector<Window*> child_vector; // �ڽ�������� ������

public:

	void add_child(Window* child)
	{
		child->parent = this;
		child_vector.push_back(child);

		// C �Լ��� ���� �ڽ�������� ����
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
		// #1. �ڽ��� ���� ó���� �õ�
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

//		return true; // event ó���� ������ �޶�
		return false;// event �� �θ� �����쿡�� ���� �޶�
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

// ��κ��� GUI ���̺귯���� 
// �ڽ������� �̺�Ʈ => �θ� �����쿡�� �����ϰ� �˴ϴ�.

// Chain Of Responsiblity  ������ �����ε�
// ��κ� �ڽŵ��� �� ����մϴ�
// 
// C# WPF : Bubbling Event
// IOS cocoa touch : Responder Chain
// MFC : Command Routing