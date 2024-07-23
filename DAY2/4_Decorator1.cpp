// Decorator - 65 page
#include <iostream>

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 사진에 이모티콘 그리는 기능을 추가해 봅시다.
// 방법#1. 상속을 사용한 기능 추가
class Emoticon : public PhotoSticker
{
	PhotoSticker* ps;	// 핵심 : 포인터 또는 참조 멤버
						// 의도 : 외부에 이미 생성된 객체를 가리키겠다는 것
public:
	void draw()
	{
		std::cout << "##########\n"; // 추가된 기능
		ps->draw();
		std::cout << "##########\n";
	}
};

class Boarder : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "==========\n"; // 기존 사진에 "Boarder" 기능 추가
		PhotoSticker::draw(); // 기존 기능
		std::cout << "==========\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();

	Emoticon e(&ps); // ps 객체에 "이모티콘" 기능을 추가
	e.draw();

	Boarder b(&ps);
	b.draw();
}

// 위 코드의 문제점

// 1. 이미 촬영된 사진에 "emoticon"을 추가한 것이 아니라
// 2. "emoticon"을 추가하기 위해 다시 사진을 촬영한 것

// 핵심 : 상속은 "객체"가 아닌 "클래스"에 기능을 추가한 것!!
// 우리가 원하는 것은
// PhotoSticker ps;
// ps.take();

// 이미 촬영된 ps 객체에 "기능"을 추가하고 싶은것
