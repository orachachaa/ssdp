#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER> > m;

public:
	void addObserver(const std::string& key, HANDLER h)
	{
		m[key].push_back(h);
	}
	void postNotificationWithName(const std::string& key, void* hint)
	{
		for( auto f : m[key] )  // m[key] �� vector
		{ 
			f(hint);
		}
	}
};

void foo(void* p)		 { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// IOS ���̺귯���� "�뺸����" �� �ֽ��ϴ�.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", &goo);
	nc.addObserver("DISCONNECT_WIFI", &goo);


	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




