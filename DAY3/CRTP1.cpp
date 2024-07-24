// CRTP1
#include <iostream>

class Window
{
public:
	// 발생된 이벤트를 조사해서 약속된 함수 호출
	void event_loop()
	{
		on_click();
	}
	void on_click() { std::cout << "window on_click\n"; }
};

// 위 라이브러리의 사용자 코드
class MainWindow : public Window
{
public:
	void on_click() { std::cout << "MainWindow on_click\n"; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}