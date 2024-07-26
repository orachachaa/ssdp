// 1_State1 - 182 page
#include <iostream>

// 방법 #1. 제어문 사용
// => 새로운 ITEM 이 나오면 모든 동작함수가 수정되어야 한다.
// => OCP 를 만족할수 없다.

class Character
{
	int gold;
	int item;
public:
	void run() 
	{ 
		if ( item == 1)
			std::cout << "run" << std::endl; 

		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack()
	{
		if (item == 1)
			std::cout << "attack" << std::endl;

		else if (item == 2)
			std::cout << "power attack" << std::endl;
	}
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



