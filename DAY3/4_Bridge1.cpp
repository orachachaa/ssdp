// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
//	void use(IPod* p) // 교체 불가능, 한가지 제품만 사용하겠다는 의미.
	void use(IMP3* p) // 약한 결합, 교체 가능, 다양한 MP3 제품 사용가능.
	{
		p->play();
		p->stop();

		// 아래 기능을 요구한다!!(1분만 듣기)
		// => 요구사항을 만족하려면 "인터페이스(IMP3)" 를 변경해야 한다.
		// => 모든 MP3 제품이 변해야 한다!! 너무 어려운 작업!!
		p->play_one_minute();
	}
};
int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


