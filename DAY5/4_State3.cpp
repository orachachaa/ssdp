// 1_State1 - 182 page
#include <iostream>

// 게임의 캐릭터를 생각해 봅시다.
// Item 획득에 따라 기존 캐릭터의 다양한 동작을 변경하고 싶다.
class Charater
{
	int gold;
	int item;
public:
	void run() { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public Charater
{
public:
	void do_run() { std::cout << "fast run" << std::endl; }
	void do_attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new SuperItem;
	p->run();
	p->attack();
}



