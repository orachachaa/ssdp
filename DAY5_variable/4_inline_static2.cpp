// Sample.h
class Sample
{
public:
	void foo();

	static int data;
};

// int Sample::data = 0;
inline int Sample::data = 0; // 중복 선언도 가능.

// Sample.cpp
// #include "Sample.h"

int Sample::data = 0;

void Sample::foo()
{
}