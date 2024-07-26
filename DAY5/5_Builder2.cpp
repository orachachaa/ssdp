// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

struct IBuilder
{
	virtual Hat make_hat() = 0;
	virtual Uniform make_uniform() = 0;
	virtual Shoes make_shoes() = 0;
	virtual ~IBuilder() {}
};

// ĳ���͸� ����� Ŭ����
class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		Character c;
		c = c + builder->make_hat();
		c = c + builder->make_uniform();
		c = c + builder->make_shoes();
		return c;
	}
};

class Korean : public IBuilder
{
public:
	Hat make_hat() override { return "��"; }
	Uniform make_uniform() override { return "�Ѻ�"; }
	Shoes make_shoes() override { return "¤��"; }
};

class American : public IBuilder
{
public:
	Hat make_hat() override { return "�߱�����"; }
	Uniform make_uniform() override { return "�纹"; }
	Shoes make_shoes() override { return "����"; }
};

int main()
{
	Korean k;
	American a;

	Director d;

	d.set_builder(&k);
	//d.set_builder(&a);

	Character c = d.construct();
	std::cout << c << std::endl;
}
