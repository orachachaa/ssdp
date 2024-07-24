#include "monitor.h"

// ��ȭ�� �������� ����� ������ �ϴ� �Լ�
void set_for_watch_video(Monitor& m)
{
	m.set_brightness(100);
	m.set_resolution(1920);
}

int main()
{
	Monitor m;
	m.info();

	// � ���� �ϰ� �ʹٸ�

	// #1. �� ���� ���� �ϰų�
	m.set_brightness(90);
	m.info();	

	// #2. �� ���� �ϴ� �Լ��� ȣ���ϸ� �˴ϴ�.
	set_for_watch_video(m);
	m.info();
}