#define USING_GUI
#include "cppmaster.h"
#include <map>

// Ŭ���� ���ø� ���鶧
// => ��� �Լ� �ȿ��� ���ø� ����"T" �� ������� ���� ����� �ִٸ�
// => ���ø��� �ƴ� ��� Ŭ������ ���� �����Ѵ�

class WindowBase
{
protected:
	int handle;
	inline static map<int, WindowBase*> this_map;
public:
	void on_lbutton_down() {}
	void on_key_down() {}

	// �׿� �پ��� ��� �Լ���
	void move() {}
	void hide() {}
};

template<typename T>
class Window : public WindowBase
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

	void on_lbutton_down() {}
	void on_key_down() {}
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

