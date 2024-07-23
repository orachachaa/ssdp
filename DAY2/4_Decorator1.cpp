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

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)

	Emoticon e;
	e.take();	
	e.draw();	

}
