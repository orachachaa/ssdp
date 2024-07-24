#include "monitor.h"

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

	void execute() {
		old_value = value;
		m.set_brightness(value);
	}

	void undo() { m.set_brightness(old_value); }
};

int main()
{
	Monitor m;

	int old_value = m.get_brightness();
	m.set_brightness(90);

	m.set_brightness(old_value);

	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}