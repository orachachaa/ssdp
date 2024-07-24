#include <iostream>

// 아래 코드에서 MainWindow 의 on_click() 을 호출하려면 "가상함수" 이어야 한다.
// 그런데...
// => event 처리 함수의 갯수는 아주 많다. - 가상함수 테이블의 오버헤드

// 가상함수를 사용하지 말고!!! 
// CRTP 로 해결해 보자.

template<typename T>
class Window
{
public:
	void event_loop()	// void event_loop(Window* this)
	{
//		on_click();		// this->on_click() 인데 this가 Window*		
		
		static_cast<T*>(this)->on_click();
	}
	void on_click() { std::cout << "window on_click\n"; }		
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