#include <iostream>

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
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

int main()
{
}
