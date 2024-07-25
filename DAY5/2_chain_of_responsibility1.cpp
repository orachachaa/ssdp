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

int main()
{
}
