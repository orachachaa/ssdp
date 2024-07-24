// CRTP1
#include <iostream>

template<typename T>
class Window
{
public:
	void event_loop()
	{
		//on_click();
		static_cast<T*>(this)->on_click();
	}
	void on_click() { std::cout << "window on click\n"; }
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