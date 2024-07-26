#include <iostream>

// 방법 #2. 변하는 것을 가상함수로!!

class Character
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run()    { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public Character
{
public:
	void do_run()    { std::cout << "fast run" << std::endl; }
	void do_attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new SuperItem;	// 기존 객체의 동작이 변경된것이 아니라
						// 동작이 다른 "또 다른 객체" 를 생성한것!!
						// 우리가 필요한 것은 "기존 객체에 동작만 변경"
						// 즉, 데이타는 유지하고 동작을 변경하고 싶은 것 
	p->run();
	p->attack();

}



