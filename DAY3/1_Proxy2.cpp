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
		std::cout << "������ �����ؼ� "
			<< url << "�� ���� IP ���� �����\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));

		ip = "100.100.100.100";
	}

	std::string get_ip() { return ip; }
};

// Ư�� URL �� IP �� �����ϴ� �۾��� ���� �ϰ� �ȴٰ� ������ ���ô�.
// ���� ���Ǵ� URL-IP ������ ���Ͽ� �����ߴٰ� ����Ҽ� �ִ� Ŭ������
// ����� ���ô�.
class DNSProxy : public IDNS
{
	std::string ip;
public:
	DNSProxy(const std::string& url)
	{
		// #1. local pc �� ����� ���Ͽ��� ������ ã��
		if (url == "www.naver.com")
			ip = "200.200.200.200";
		else
		{
		// #2. ������ ���ٸ� DNS Ŭ���� ���
			DNS dns(url);
			ip = dns.get_ip();
		}
	}
	std::string get_ip() { return ip; }
};



int main()
{
//	DNS dns("www.naver.com"); // �׻� �������� ���� ���
//	DNSProxy dns("www.naver.com");	// 1. cache ���� ã��!!
									// 2. ������ ���� ����(DNS Ŭ���� ���)

	DNSProxy dns("www.samsung.com");

	std::cout << dns.get_ip() << std::endl;
}

// proxy ���� : �����ڸ� ����� ����

// virtual proxy : ����� ���� ��� ��ü�� ������ �ִ��� �ʰ� �ϵ��� �ϴ� ����
//				   �� �ڵ��� DNSProxy

// remote proxy : ������ ��ü�� ���� local ǥ��( ��������)

// 77 page