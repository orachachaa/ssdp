#define USING_GUI
#include "cppmaster.h"
#include <map>


class Window
{
	int handle;

	inline static map<int, Window*> this_map;	// 핵심
												// QT, MFC, wxWidget등
												// 대부분의 GUI 라이브러리
												// 가 내부적으로 사용하는 기술
							// [윈도우번호, this] 를 보관하는 자료구조

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		// this 를 자료구조에 보관합니다.
		// => static 멤버 함수에서 "키값 인 윈도우 핸들" 만 알수 있다면
		//    this 를 사용할수 있게 됩니다.
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		// 이제 self 가 this 이므로
		// 모든 멤버 데이타, 멤버 함수에 접근 가능합니다.

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

// 이제 라이브러리 사용자는 Window 파생 클래스를 만들어서
// 약속된 가상함수를 override 하면 됩니다.
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

