#include <iostream>

// Ŭ������ ���ø����� �ϸ�, Ÿ�� ���ڿ� ���� �ٸ� Ŭ���� ����
// => Window<A>, Window<B> �� �ٸ� Ŭ����

// Window Ŭ������ ���� ū Ŭ���� �Դϴ�. ( ��� �Լ��� ���ʰ�!!!!)

// Window Ŭ���� �ȿ��� T �� ������� ���� ��� ��� �Լ���
// => template �� �ƴ� ��� Ŭ������ ���� �����ؾ� �մϴ�.

class WindowBase
{
public:
	// �����츦 �����ϴ� ���ʰ��� ��� �Լ���
	void move() {}
	void resize() {}

	// �̺�Ʈ ó���� ���� ���ʰ��� ��� �Լ���
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