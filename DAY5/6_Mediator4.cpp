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
		for( auto f : m[key] )  // m[key] 는 vector
		{ 
			f(hint);
		}
	}
};

void foo(void* p)		 { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// IOS 라이브러리에 "통보센터" 가 있습니다.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", &goo);
	nc.addObserver("DISCONNECT_WIFI", &goo);


	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




