#include <iostream>
#include <string>
#include <thread>
#include <chrono>

struct IDNS
{
	virtual std::string get_ip() = 0;
	virtual ~IDNS() {}
};

class DNS : public IDNS
{
	std::string ip;
public:
	DNS(const std::string& url)
	{
		std::cout << "서버에 접속해서 "
			<< url << "에 대한 IP 정보 얻는중\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));

		ip = "100.100.100.100";
	}

	std::string get_ip() { return ip; }
};

// 특정 URL 을 IP 로 변경하는 작업을 자주 하게 된다고 가정해 봅시다.
// 자주 사용되는 URL-IP 정보를 파일에 보관했다가 사용할수 있는 클래스를
// 만들어 봅시다.
class DNSProxy : public IDNS
{
	std::string ip;
public:
	DNSProxy(const std::string& url)
	{
		// #1. local pc 에 저장된 파일에서 정보를 찾기
		if (url == "www.naver.com")
			ip = "200.200.200.200";
		else
		{
		// #2. 정보가 없다면 DNS 클래스 사용
			DNS dns(url);
			ip = dns.get_ip();
		}
	}
	std::string get_ip() { return ip; }
};



int main()
{
//	DNS dns("www.naver.com"); // 항상 서버에서 정보 얻기
//	DNSProxy dns("www.naver.com");	// 1. cache 에서 찾고!!
									// 2. 없으면 서버 접속(DNS 클래스 사용)

	DNSProxy dns("www.samsung.com");

	std::cout << dns.get_ip() << std::endl;
}

// proxy 패턴 : 대행자를 만드는 패턴

// virtual proxy : 비용이 많이 드는 객체의 생성을 최대한 늦게 하도록 하는 패턴
//				   위 코드의 DNSProxy

// remote proxy : 원격지 객체에 대한 local 표현( 다음예제)

// 77 page