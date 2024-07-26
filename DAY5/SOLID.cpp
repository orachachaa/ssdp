#include <iostream>

// SOLID 
// SRP : Single Responsibility Principle => �ϳ��� Ŭ������ �ϳ��� å��(���)��!!
// OCP : Open Close Principle            => ���Ȯ�忡 ���� �ְ�, �ڵ� �������� ���� �־��!!
// LSP : Liskov Substitution Principle
// ISP : Interface Segregation Principle
// DIP : Dependency Inversion Principle        


//-------------------------------------------------------
// LSP ( Liskov Substitution Principle )
// => �������� ��� ����� ���� ġȯ�� ��Ģ
// => ��� Ŭ������ �ʿ��� ���� �Ļ� Ŭ������ ġȯ�Ҽ� �־�� �Ѵ�.

class Car
{
public:
	virtual void Go() { std::cout << "Go\n"; }
};
class SuperCar : public Car
{
public:
	void Go() override { std::cout << "fast Go\n"; }
};
class FlyingCar : public Car
{
public:
	void Fly() {}
	void Go() override { throw UnsupportedOperation(); }
};

void foo(Car* c) // ��� Ŭ������ ���Ǵ� ��
{
	c->Go();
}

foo(new SuperCar);
foo(new FlyingCar);

//---------------------------------------------------
// ISP ( Interface Segregation Principle )
// => �������̽��� �ݸ��� ��Ģ
// => �� Ŭ���̾�Ʈ�� �ʿ�� �ϴ� �������̽����� �и������ν�, 
//    Ŭ���̾�Ʈ�� ������� �ʴ� �������̽��� ������ �߻��ϴ��� 
//    ������ ���� �ʵ��� ������ �ϴ� ���� �ٽ��̴�.

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual void upload_sns() = 0;
	virtual ~IMP3() {}
};

struct ISNS
{
	virtual void upload_sns() = 0;
	virtual ~ISNS() {}
};

void only_listening_music(IMP3* mp3)
{
	mp3->play();
	mp3->stop();
}

//----------------------------------------------
// DIP ( Dependency Inversion Principle )
// => ���� ���� ������ ��Ģ
// => ���� ����� ���� ����� ���� ������ �����ϸ� �ȵȴ�.
// => ���� ����� �߻� �����ؾ� �Ѵ�.
// => ���� ���׿� �������� ����, �߻� �����϶�� ��
class People
{
public:
	void use(HDCamera* c) { c->take(); }  // DIP ����
	void use(ICamera* c) { c->take(); }  // DIP �ؼ�

	// People �� ī�޶� �ʿ�������, 
	// 1. ��ü���� ���� ���(HDCamera)�� �������� �ʰ�
	// 2. �߻�(ICamera) �� �����ϰ� �ȴ�.
};