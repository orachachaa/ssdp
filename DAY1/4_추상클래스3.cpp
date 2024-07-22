//1_�߻�Ŭ����2.cpp
#include <iostream>

// ���� H/W �� ��κ� OCP �� �����մϴ�.
// => �� ��ǰ�� ���Ѿ��ϴ� ��Ģ(ex. usb protocol) ���� �ֱ� ������)

// S/W �� ��Ģ�� ���� ����� "OCP" �� �����Ҽ� �ִ�

 
// ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�

class ICamera
{
public:
	virtual void take() = 0;
};

// ���� ī�޶� ����Ҷ��� "��Ģ" ��θ� ����ϸ� �˴ϴ�.
// ��ü���� ��ǰ�̸��� ���ʿ䵵 �����ϴ�.
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



