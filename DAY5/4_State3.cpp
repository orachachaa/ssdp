// 1_State1 - 182 page
#include <iostream>

// ������ ĳ���͸� ������ ���ô�.
// Item ȹ�濡 ���� ���� ĳ������ �پ��� ������ �����ϰ� �ʹ�.
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



