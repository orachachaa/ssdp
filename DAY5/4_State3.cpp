#include <iostream>

// ��� #2. ���ϴ� ���� �����Լ���!!

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

	p = new SuperItem;	// ���� ��ü�� ������ ����Ȱ��� �ƴ϶�
						// ������ �ٸ� "�� �ٸ� ��ü" �� �����Ѱ�!!
						// �츮�� �ʿ��� ���� "���� ��ü�� ���۸� ����"
						// ��, ����Ÿ�� �����ϰ� ������ �����ϰ� ���� �� 
	p->run();
	p->attack();

}



