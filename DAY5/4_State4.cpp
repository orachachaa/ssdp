#include <iostream>

// 방법 #3. 변하는 것을 다른 클래스로

// 캐릭터의 모든 동작을 나타내는 인터페이스
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 그외에 slide(), jump(), fly()
};

// 캐릭터의 아이템 상태에 따라 동작이 변경되어야 한다.
// 동작만 클래스로 설계
// => 멤버 데이타는 없고, 멤버 함수만.
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

	IState* state = &state1; // 초기 상태는 아이템이 없는 상태

	int gold;
	int item;
public:
	void set_item() 
	{ 
		state = &state2;  // 멤버 함수 전체를 교체하는 의미.

		// 타이머등을 설치해서, 
		// 10초 뒤에 다시 "state = &state1" 로 하도록!!
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

// strategy 와 state 패턴은 동일한 클래스 Diagram 입니다.



// strategy : 객체가 사용하는 한개의 알고리즘의 교체
//			  주로 외부적 요인에 의해 교체 됩니다.
//			  Edit edit;
//			  edit.set_validator(&v1); // 외부에서 교체 하고
//			  edit.set_validator(&v2); // 객체의 전체 동작이 아닌
//										// 내부적으로 사용하는 알고리즘 교체
//

// state : 객체의 거의 모든 동작을 교체 하는 것
//         내부적인 알고리즘이 아닌 사용자가 사용하는 모든 동작들..
//         외부에서 교체가 아닌 "내부 상태" 에 따른 동작 교체

// 자판기 
// 멤버 함수 : insert_coin(), select_coffee()
// 동전을 넣었을때의 동작에 대한 함수들
// 동전을 넣지 않았을때의 동작에 대한 함수들

// 결국, 객체의 상태에 따라서 
// 달라지는 멤버 함수를 별도의 클래스로 설계 하는 것. 