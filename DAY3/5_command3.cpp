#include "monitor.h"

// Command ���� : ����� ĸ��ȭ(Ŭ����) �Ѵ�.

// C ������ � ���� �ϰ� ������
// => ���� �ϰų�, �ش����� �����ϴ� �Լ��� ����� �˴ϴ�.
// => �� ���, "�ش���"�� �Ҽ� �ֽ��ϴ�.


// command ���� : �ؾ��� ���� Ŭ������ ���� �մϴ�.
// => "�ؾ�����" + "����ϴ� ���" + "����Ҷ� �ʿ��� ����"�� ��� ������ �ֽ��ϴ�.
// => ����� �ڷᱸ���� �����ߴٰ� ���߿� �����Ҽ��� �ֽ��ϴ�.


// �ᱹ ��� ������ ���� �߰����� �����

// main <=====================================> m.set_brightness()
// main <============ BrightCommand ==========> m.set_brightness()

struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() {};
	virtual ~ICommand() {}
};


class BrightCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	BrightCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() 
	{
		old_value = m.get_brightness();
		m.set_brightness(value); 
	}
	void undo()
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;

	// #1. command ������ ������� ���� �ڵ�
	
	int old_value = m.get_brightness();

	m.set_brightness(90); // A

	// m �� A�� ���� ���·� ����� ������(undo)
	m.set_brightness(old_value);



	// #2. command ������ ����ϴ� �ڵ�.
	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}