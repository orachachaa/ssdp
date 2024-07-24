#include "monitor.h"

// Command 패턴 : 명령을 캡슐화(클래스) 한다.

// C 언어에서는 어떤 일을 하고 싶을때
// => 직접 하거나, 해당일을 수행하는 함수를 만들게 됩니다.
// => 이 경우, "해당일"만 할수 있습니다.


// command 패턴 : 해야할 일을 클래스로 설계 합니다.
// => "해야할일" + "취소하는 방법" + "취소할때 필요한 정보"을 모두 담을수 있습니다.
// => 명령을 자료구조에 보관했다가 나중에 실행할수도 있습니다.


// 결국 명령 실행을 위한 중간층을 만든것

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

	// #1. command 패턴을 사용하지 않은 코드
	
	int old_value = m.get_brightness();

	m.set_brightness(90); // A

	// m 을 A의 이전 상태로 만들어 보세요(undo)
	m.set_brightness(old_value);



	// #2. command 패턴을 사용하는 코드.
	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}