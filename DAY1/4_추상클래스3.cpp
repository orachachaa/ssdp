//1_�߻�Ŭ����2.cpp
#include <iostream>

// ���� H/W �� ��κ� OCP �� �����մϴ�.
// => �� ��ǰ�� ���Ѿ��ϴ� ��Ģ(ex. usb protocol) ���� �ֱ� ������)

// S/W �� ��Ģ�� ���� ����� "OCP" �� �����Ҽ� �ִ�

//----------------------------
// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, Ŭ���� �̸��� ���� ����ϴ� ��
// => use_camera(HDCamera*)
// => ��ü �Ұ����� ������ ������


// ���� ����(loosely coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, 
//    ��Ģ�� ���� �������̽�(�߻�Ŭ����)�� ���ؼ� ���
// => use_camera( ICamera*)
// => ��ü ������ ������ ������


// �������̽� vs �߻�Ŭ����
// �������̽� : ���Ѿ� �ϴ� ��Ģ�� ���� ��
// �߻�Ŭ���� : ���Ѿ� �ϴ� ��Ģ + �ٸ� ���

// java, C# : ������ interface, abstract Ű���� ����
// C++      : ������ Ű���� ����, ���� �߻�Ŭ���� ������ ����.
//------------------------------------------------------------
 
// ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ�" �Ǿ�� �Ѵ�. ��� ���� ����
//        "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ���ϴ� ���� �����ϴ�.

//class ICamera		// class : ���� ������ ������ private
struct ICamera		// struct: ���� ������ ������ public
{	
//public:
	virtual void take() = 0;

	virtual ~ICamera() {}	// �������̽��� �ᱹ ���������δ� ��� Ŭ���� �Դϴ�.
							// C++���� ��� Ŭ���� �Ҹ��ڴ� �����Լ��̾�� �մϴ�.
};




// ���� ī�޶� ����Ҷ��� "��Ģ" ��θ� ����ϸ� �˴ϴ�.
// ��ü���� ��ǰ�̸��� ���ʿ䵵 �����ϴ�.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// ���� ��� ī�޶� ��ǰ�� "��Ģ"�� ���Ѿ� �մϴ�.
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
	p.use_camera(&uhc); // ok. ���߿� �߰��� Ŭ���� ������ 
						// People Ŭ���� �������� ��밡���ϴ�.
						// OCP ����!
}



