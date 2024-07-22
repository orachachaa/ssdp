//1_추상클래스2.cpp
#include <iostream>

// 요즘 H/W 는 대부분 OCP 를 만족합니다.
// => 각 제품이 지켜야하는 규칙(ex. usb protocol) 등이 있기 때문에)

// S/W 도 규칙을 먼저 만들면 "OCP" 를 만족할수 있다

 
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다

class ICamera
{
public:
	virtual void take() = 0;
};

// 이제 카메라를 사용할때는 "규칙" 대로만 사용하면 됩니다.
// 구체적인 제품이름을 알필요도 없습니다.
class People
{
public:
	void use_camera(? c) { c->take(); }
};










class Camera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ???
}



