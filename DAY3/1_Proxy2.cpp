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
	DNS dns("www.samsung.com");

	std::cout << dns.get_ip() << std::endl;
}