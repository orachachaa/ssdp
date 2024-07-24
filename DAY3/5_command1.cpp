#include "monitor.h"

// 영화를 보기위한 모니터 설정을 하는 함수
void set_for_watch_video(Monitor& m)
{
	m.set_brightness(100);
	m.set_resolution(1920);
}

int main()
{
	Monitor m;
	m.info();

	// 어떤 일을 하고 싶다면

	// #1. 그 일을 직접 하거나
	m.set_brightness(90);
	m.info();	

	// #2. 그 일을 하는 함수를 호출하면 됩니다.
	set_for_watch_video(m);
	m.info();
}