#define USING_GUI
#include <atomic>
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
//	int refcnt = 0;
	std::atomic<int> refcnt = 0; // 스레드 안전한 int

	int server;
public:

	void AddRef()  { ++refcnt;  }
	void Release() { if (--refcnt == 0) delete this; }

	Calc() { server = ec_find_server("Calc"); }

	~Calc() { std::cout << "~Calc\n"; }


	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}

