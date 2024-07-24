#include "monitor.h"

// Command ���� : ����� ĸ��ȭ(Ŭ����) �Ѵ�.

class BrightCommand
{
	Monitor& m;
	int value;
public:
	BrightCommand(Monitor& m, int value) : m(m), value(m) {}

	void execute() { m.set_brightness(value); }
};

int main()
{
	Monitor m;

	// #1. command ������ ������� ���� �ڵ�
	m.set_brightness(90);
	
	// #2. command ������ ����ϴ� �ڵ�.
	BrightCommand cmd(m, 90);
	cmd.execute();
}