#include <iostream>

// 클래스를 템플릿으로 하면, 타입 인자에 따라서 다른 클래스 생성
// => Window<A>, Window<B> 는 다른 클래스

// Window 클래스는 아주 큰 클래스 입니다. ( 멤버 함수가 수십개!!!!)

// Window 클래스 안에서 T 를 사용하지 않은 모든 멤버 함수는
// => template 이 아닌 기반 클래스를 만들어서 제공해야 합니다.

class WindowBase
{
public:
	// 윈도우를 조작하는 수십개의 멤버 함수들
	void move() {}
	void resize() {}

	// 이벤트 처리를 위한 수십개의 멤버 함수들
	void on_click() { std::cout << "window on_click\n"; }
};


template<typename T>
class Window : public WindowBase
{
public:
	void event_loop()	
	{
		static_cast<T*>(this)->on_click();
	}

};


class MainWindow : public Window< MainWindow >
{
public:
	void on_click() { std::cout << "MainWindow on_click\n"; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}