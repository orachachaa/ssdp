#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;


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
		WSACleanup();
	}
};

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


// TCPServer 를 만들려면
// 1. 몇 개의 클래스를 사용해서
// 2. 몇 단계의 과정을 거쳐야 합니다.

// => 이런 과정 자체를 단순화 하는 (책임지는 )
//    상위 레벨의 클래스를 제공합니다.

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM };
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	TCPServer server;
	server.Start("100.100.100.100", 3000);
}

//----------------------------------------------

// 3차 API : 특정 작업을 수행하는 데 필요 한 클래스들과 절차를 단순화하는
//           상위 레벨의 클래스
//			 목표 : 사용하기 쉽게
//			 facade 패턴 => "건물의 정면" 이라는 의미
//------------------------------------------------------------------
// 2차 API : C++, C#, Java 등의 객체지향 언어 사용
//           1차 API 의 각 분야와 1:1로 매핑되는 클래스 제공 - 단일 책임원칙
//------------------------------------------------------------------
// 1차 API : C언어 기반 - 다양한 분야에 대한 수백~수천개 함수, 구조체 제공
//-------------------------------------------------------------
// OS      : windows, linux, osx, ios, android => 전부 C 언어 
