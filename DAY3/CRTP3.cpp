// CRTP1
#include <iostream>

class WindowBase
{
public:
	void move() {}
	void resize() {}
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

class MainWindow : public Window<MainWindow>
{
public:
	void on_click() { std::cout << "MainWindow on_click\n"; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}