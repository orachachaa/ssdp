#include <iostream>

struct Handler
{
	Handler* next = nullptr;

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
