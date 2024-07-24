// CRTP1
#include <iostream>

class Window
{
public:
	void event_loop()
	{
		on_click();
	}
	void on_click() { std::cout << "window on click\n"; }
};

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