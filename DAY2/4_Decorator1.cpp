// Decorator - 65 page
#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 스티커 사진에 이모티콘 그리는 기능을 추가해 봅시다.
// 방법#1. 상속을 사용한 기능 추가
class Emoticon : public PhotoSticker
{
public:
	void draw() 
	{ 
		std::cout << "###############\n";	// 추가된 기능
		PhotoSticker::draw();				// 기존 기능
		std::cout << "###############\n";
	}
};

class Border : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "===============\n";	// 기존 사진에 "Border" 기능추가
		PhotoSticker::draw();				// 
		std::cout << "===============\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)

	Emoticon e;
	e.take();	
	e.draw();	

	Border b;
	b.take();
	b.draw();
}

// 위 코드의 문제점

// 1. 이미 촬영된 사진에 "emoticon" 을 추가한 것이 아니라
// 2. "emoticon" 을 추가하기 위해 다시 사진을 촬영 한것

// 핵심 : 상속은 "객체" 가 아닌 "클래스" 에 기능을 추가한것!!
// 우리가 원하는 것은
// PhotoSticker ps;
// ps.take();

// 이미 촬영된 ps 객체에 "기능" 을 추가하고 싶은것
