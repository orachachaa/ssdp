#include <iostream>

// Chain Of Responsibility
// => 책임의 고리(연쇄, 이동, 전가) 등으로 번역

// 아래 코드가 "이패턴의 핵심 코드" 입니다.
class Handler
{
	Handler* next = nullptr;
public:
	Handler* SetNext(Handler* h)
	{
		next = h;
		return h;
	}


	void Handle(int problem)
	{
		// #1. 자신이 먼저 처리를 시도
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};


class Team1 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Start Team1\n";

		if (problem == 7)
		{
			std::cout << "Resolved by Team1\n";
			return true;
		}
		std::cout << "End Team1\n";

		return false;
	}
};

class Team2 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Start Team2\n";

		if (problem % 2 == 1)
		{
			std::cout << "Resolved by Team2\n";
			return true;
		}
		std::cout << "End Team2\n";

		return false;
	}
};

class Team3 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Start Team3\n";

		if (problem < 10 )
		{
			std::cout << "Resolved by Team3\n";
			return true;
		}
		std::cout << "End Team3\n";

		return false;
	}
};
int main()
{
	Team1 t1;
	Team2 t2;
	Team3 t3;

	t1.SetNext(&t2)->SetNext(&t3);

	t1.Handle(7);
}
