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
};


class People
{
public:
	void use(IMP3* p) 
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


