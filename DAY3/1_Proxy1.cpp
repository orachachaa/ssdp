#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Domain Name Server : url => ip 로 변경
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

int main()
{
	DNS dns("www.samsung.com");

	std::cout << dns.get_ip() << std::endl;
}