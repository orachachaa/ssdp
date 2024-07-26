#include <iostream>

// ��� #3. ���ϴ� ���� �ٸ� Ŭ������

// ĳ������ ��� ������ ��Ÿ���� �������̽�
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// �׿ܿ� slide(), jump(), fly()
};

// ĳ������ ������ ���¿� ���� ������ ����Ǿ�� �Ѵ�.
// ���۸� Ŭ������ ����
// => ��� ����Ÿ�� ����, ��� �Լ���.
class NoItem : public IState
{
public:
	void run() override    { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};
class SuperItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class Character
{
	NoItem    state1;
	SuperItem state2;

	IState* state = &state1; // �ʱ� ���´� �������� ���� ����

	int gold;
	int item;
public:
	void set_item() 
	{ 
		state = &state2;  // ��� �Լ� ��ü�� ��ü�ϴ� �ǹ�.

		// Ÿ�̸ӵ��� ��ġ�ؼ�, 
		// 10�� �ڿ� �ٽ� "state = &state1" �� �ϵ���!!
	}

	void run() { state->run(); }
	void attack() { state->attack(); }
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->set_item();
	p->run();
	p->attack();


}




