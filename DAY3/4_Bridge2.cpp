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
//----------------------------------------------------------
// People(Client) 가 IMP3(실제 제품) 을 직접 사용하게 하지 말고
// 중간층(간접층, 추상층) 을 제공해서 사용하게 한다.

class MP3
{
	IMP3* implementor;
public:
	MP3(IMP3* p = nullptr) : implementor(p)
	{
		if (implementor == nullptr)
			implementor = new IPod;
	}
	void play() { implementor->play(); }
	void stop() { implementor->stop(); }

	void play_one_minute()
	{
		implementor->play();

		// 1분 타이머 설치하고.. 타이머신호에서
		implementor->stop();
	}

};

// 이제 모든 코드에서는 
// 실제 구현층(IMP3 인터페이스와, 실제 제품들)을 사용하지 말고
// 중간층(추상층)을 사용하도록 합니다.

// 구현과 추상을 분리해서 상호 독립적인 update 가 되게 한다.
// => 핵심 : People<->IMP3  를 People<->MP3<->IMP3 로 하면 유연성이 증대 된다는 것
class People
{
public:
	void use(MP3* p) 
	{
		p->play();
		p->stop();


		p->play_one_minute();
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


