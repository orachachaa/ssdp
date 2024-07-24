#include "monitor.h"

// Command 패턴 : 명령을 캡슐화(클래스) 한다.

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

	// #1. command 패턴을 사용하지 않은 코드
	m.set_brightness(90);
	
	// #2. command 패턴을 사용하는 코드.
	BrightCommand cmd(m, 90);
	cmd.execute();
}