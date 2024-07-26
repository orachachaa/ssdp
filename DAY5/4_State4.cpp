// 1_State1 - 182 page
#include <iostream>

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// slide(), jump(), fly()
};

class NoItem : public IState
{
public:
	void run() override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run() override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class Charater
{
	NoItem state1;
	SuperItem state2;

	IState* state = &state1;

	int gold;
	int item;
public:
	void set_item()
	{
		state = &state2;

		// 타이머로 10초 뒤에 state를 state1으로 원복
	}
	void run() { state->run(); }
	void attack() { state->attack(); }
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p->set_item();
	p->run();
	p->attack();
}



