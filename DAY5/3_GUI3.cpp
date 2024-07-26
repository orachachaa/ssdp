#define USING_GUI
#include "cppmaster.h"
#include <map>


class Window
{
	int handle;

	inline static map<int, Window*> this_map;	// �ٽ�
												// QT, MFC, wxWidget��
												// ��κ��� GUI ���̺귯��
												// �� ���������� ����ϴ� ���
							// [�������ȣ, this] �� �����ϴ� �ڷᱸ��

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		// this �� �ڷᱸ���� �����մϴ�.
		// => static ��� �Լ����� "Ű�� �� ������ �ڵ�" �� �˼� �ִٸ�
		//    this �� ����Ҽ� �ְ� �˴ϴ�.
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		// ���� self �� this �̹Ƿ�
		// ��� ��� ����Ÿ, ��� �Լ��� ���� �����մϴ�.

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
//			on_lbutton_down();  // this->on_lbutton_down();
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

// ���� ���̺귯�� ����ڴ� Window �Ļ� Ŭ������ ����
// ��ӵ� �����Լ��� override �ϸ� �˴ϴ�.
class MainWindow : public Window
{
public:
	void on_lbutton_down() override
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

