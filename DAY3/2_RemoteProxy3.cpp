#define USING_GUI
#include "cppmaster.h"

// Proxy 는 Update 될수 있습니다
// 교체 가능한 설계를 위해서 인터페이스를 먼저 설계
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

// Proxy 를 만드는 사람   : Server 제작자
// Proxy 를 사용하는 사람 : Client 제작자

int main()
{
	// Proxy 를 아래 처럼 사용하면 
	// "강한결합" 이 됩니다.
	// 새로운 Proxy 가 배포되면 아래 코드는 수정되어야 합니다.
	// OCP 위반
	// Calc* calc = new Calc;

	// 약한결합으로 사용해야 합니다.

	ICalc* calc = new ? ; // ? 를 어떻게 해야 할까요 ?


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





