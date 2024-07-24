#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 대행자(proxy) 를 만들어 봅시다.

class Calc
{
	int server;
public:
	Calc() {}

	int Add(int a, int b) { return ? };
	int Sub(int a, int b) { return ? };
};


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





