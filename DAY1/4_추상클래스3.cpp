//1_추상클래스2.cpp
#include <iostream>

// 요즘 H/W 는 대부분 OCP 를 만족합니다.
// => 각 제품이 지켜야하는 규칙(ex. usb protocol) 등이 있기 때문에)

// S/W 도 규칙을 먼저 만들면 "OCP" 를 만족할수 있다

//----------------------------
// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는 것
// => use_camera(HDCamera*)
// => 교체 불가능한 경직된 디자인


// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시, 
//    규칙을 담은 인터페이스(추상클래스)를 통해서 사용
// => use_camera( ICamera*)
// => 교체 가능한 유연한 디자인


// 인터페이스 vs 추상클래스
// 인터페이스 : 지켜야 하는 규칙만 담은 것
// 추상클래스 : 지켜야 하는 규칙 + 다른 멤버

// java, C# : 별도의 interface, abstract 키워드 있음
// C++      : 별도의 키워드 없음, 오직 추상클래스 문법만 있음.
//------------------------------------------------------------
 
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생" 되어야 한다. 라고 하지 말고
//        "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현하는 것이 좋습니다.

//class ICamera		// class : 접근 지정자 생략시 private
struct ICamera		// struct: 접근 지정자 생략시 public
{	
//public:
	virtual void take() = 0;

	virtual ~ICamera() {}	// 인터페이스도 결국 문법적으로는 기반 클래스 입니다.
							// C++에서 기반 클래스 소멸자는 가상함수이어야 합니다.
};




// 이제 카메라를 사용할때는 "규칙" 대로만 사용하면 됩니다.
// 구체적인 제품이름을 알필요도 없습니다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// 이제 모든 카메라 제품은 "규칙"을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

	UHDCamera uhc;
	p.use_camera(&uhc); // ok. 나중에 추가된 클래스 이지만 
						// People 클래스 수정없이 사용가능하다.
						// OCP 만족!
}



