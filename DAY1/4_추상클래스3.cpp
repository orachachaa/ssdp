//1_추상클래스2.cpp
#include <iostream>

class ICamera
{
public:
	virtual void take() = 0;

	virtual ~ICamera() {}
};

class Camera : public ICamera
{
public:
	void take() override { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take UHD Picture" << std::endl; }
};

class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uc;
	p.use_camera(&uc);
}





