#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 대행자(proxy) 를 만들어 봅시다.

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

// 위 Calc 는 서버 제작자가 만들어서 "클라이언트 제작자"에게 배포하게 됩니다

// 1. Client 제작자는 IPC 를 몰라도 됩니다. "Calc 클래스만 사용"
// 
// 2. 1, 2 라는 명령 코드 대신 "Add, Sub" 사용하면 됩니다.

// 3. 서버 장애시 백업서버 연결등의 과정도 Calc Proxy 에서 하면 됩니다.

// 4. 자주 사용되는 요청의 결과도 Calc Proxy 에서 캐쉬 할수 있습니다.

// 위와 같은 "원격 서버" 에 대한 "대행자" 를 "remote proxy" 라고 합니다.

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





