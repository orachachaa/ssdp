// CRTP1
#include <iostream>

class Window
{
public:
	// �߻��� �̺�Ʈ�� �����ؼ� ��ӵ� �Լ� ȣ��
	void event_loop()
	{
		on_click();
	}
	void on_click() { std::cout << "window on_click\n"; }
};

// �� ���̺귯���� ����� �ڵ�
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