#include "monitor.h"

class BrightCommand
{
	Monitor& m;
	int value;
public:
	BrightCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() { m.set_brightness(value); }
};

int main()
{
	Monitor m;

	m.set_brightness(90);

	BrightCommand cmd(m, 90);
	cmd.execute();
}