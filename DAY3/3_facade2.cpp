#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

// SRP ( Single Responsibility Principle )
// => 단일 책임의 원칙
// => 하나의 클래스는 하나의 책임만 있어야 한다.


// N/W 라이브러리 자체에 대한 책임 - 초기화와 마무리
class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};
// IP 주소를 관리하는 클래스
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket 작업을 책임지는 클래스
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// 위와 같은 클래스가 있다면 최종 사용자는 아래처럼 만 만들면 됩니다.
// => C언어인 facade1.cpp 보다 훨씬 쉽습니다
// => 위 클래스는 라이브러리 제작자가 제공하면 됩니다.

int main()
{
	NetworkInit init;

	Socket sock(SOCK_STREAM); // TCP 서버

	IPAddress addr("127.0.0.1", 4000);

	sock.Bind(&addr);
	sock.Listen();
	sock.Accept();

}
