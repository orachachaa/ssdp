#include <iostream>

// �Ʒ� �ڵ忡�� MainWindow �� on_click() �� ȣ���Ϸ��� "�����Լ�" �̾�� �Ѵ�.
// �׷���...
// => event ó�� �Լ��� ������ ���� ����. - �����Լ� ���̺��� �������

// �����Լ��� ������� ����!!! 
// CRTP �� �ذ��� ����.

template<typename T>
class Window
{
public:
	void event_loop()	// void event_loop(Window* this)
	{
//		on_click();		// this->on_click() �ε� this�� Window*		
		
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