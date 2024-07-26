// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정



// 캐릭터를 만드는 데 필요 한 각각의 공정에 대한 
// 함수를 약속하는 인터페이스
struct IBuilder
{
	virtual Hat     make_hat() = 0;
	virtual Uniform make_uniform() = 0;
	virtual Shoes   make_shoes() = 0;
	virtual ~IBuilder() {}
};


class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		Character c;

		// 캐릭터를 만드는 공정은 동일합니다
		// => 그런데, 각 공정의 결과는 builder 의 종류에 따라 달라 집니다.
		c = c + builder->make_hat();
		c = c + builder->make_uniform();
		c = c + builder->make_shoes();
		return c;
	}
};
// 국가별 빌더들...
class Korean : public IBuilder
{
public:
	Hat make_hat() override         { return "갓 "; }
	Uniform make_uniform() override { return "한복 "; }
	Shoes make_shoes() override     { return "짚신 "; }
};

class American : public IBuilder
{
public:
	Hat make_hat() override { return "야구모자 "; }
	Uniform make_uniform() override { return "양복 "; }
	Shoes make_shoes() override { return "구두 "; }
};

int main()
{
	Korean k;
	American a;

	Director d;

//	d.set_builder(&k);
	d.set_builder(&a); // 축구게임에서 국가를 변경할때 마다
						// 해당하는 빌더로 교체 됩니다.

	Character c = d.construct();
	std::cout << c << std::endl;

}

// 대학 지원서는 "이름, 전화번호, 주소"를 적어야 합니다.
// 그런데, 어느 위치에 적는지는 대학마다 다릅니다.

// A대학 : (10, 10) 이름  (20,20) 전화
// B대학 : (30, 20) 이름  (50,50) 전화

// 지원서디렉터 d;
// d.set_builder(&A대학);