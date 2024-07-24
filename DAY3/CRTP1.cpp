// CRTP1
#include <iostream>

class Window
{
public:
	// �߻��� �̺�Ʈ�� �����ؼ� ��ӵ� �Լ� ȣ��
	void event_loop()	// void event_loop(Window* this)
	{
		on_click();		// this->on_click(); �� ����Ǵµ�..
						//					��ü�� MainWindow ������
						//					this �� Window* �̰�
						//					on_click() �� non-virtual �̹Ƿ�
						//					1��ȣ��.
						//					2���� ȣ���Ϸ��� �����̾�� �Ѵ�.		
	}
	void on_click() { std::cout << "window on_click\n"; }		// 1
};

// �� ���̺귯���� ����� �ڵ�
class MainWindow : public Window
{
public:
	void on_click() { std::cout << "MainWindow on_click\n"; }	// 2
};

int main()
{
	MainWindow w;
	w.event_loop(); // event_loop(&w) �� ����
}