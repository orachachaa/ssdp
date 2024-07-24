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

		// 1분 타이머 설치하고..
		implementor->stop();
	}
};


class People
{
public:
	//void use(IPod* p)
	//void use(IMP3* p)
	void use(MP3 *p)
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
	p.use(&pod);
}


