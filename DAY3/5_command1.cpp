#include "monitor.h"

void set_for_watch_video(Monitor& m)
{
	m.set_brightness(100);
	m.set_resolution(1024);
}

int main()
{
	Monitor m;
	m.info();

	m.set_brightness(90);
	m.info();

	set_for_watch_video(m);
	m.info();
}