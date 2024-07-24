// CRTP1
#include <iostream>

class Window
{
public:
	// 발생된 이벤트를 조사해서 약속된 함수 호출
	void event_loop()	// void event_loop(Window* this)
	{
		on_click();		// this->on_click(); 로 변경되는데..
						//					객체는 MainWindow 이지만
						//					this 가 Window* 이고
						//					on_click() 가 non-virtual 이므로
						//					1번호출.
						//					2번을 호출하려면 가상이어야 한다.		
	}
	void on_click() { std::cout << "window on_click\n"; }		// 1
};

// 위 라이브러리의 사용자 코드
class MainWindow : public Window
{
public:
	void on_click() { std::cout << "MainWindow on_click\n"; }	// 2
};

int main()
{
	MainWindow w;
	w.event_loop(); // event_loop(&w) 로 변경
}