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
// People(Client) �� IMP3(���� ��ǰ) �� ���� ����ϰ� ���� ����
// �߰���(������, �߻���) �� �����ؼ� ����ϰ� �Ѵ�.

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

		// 1�� Ÿ�̸� ��ġ�ϰ�.. Ÿ�̸ӽ�ȣ����
		implementor->stop();
	}

};

// ���� ��� �ڵ忡���� 
// ���� ������(IMP3 �������̽���, ���� ��ǰ��)�� ������� ����
// �߰���(�߻���)�� ����ϵ��� �մϴ�.

// ������ �߻��� �и��ؼ� ��ȣ �������� update �� �ǰ� �Ѵ�.
// => �ٽ� : People<->IMP3  �� People<->MP3<->IMP3 �� �ϸ� �������� ���� �ȴٴ� ��
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


