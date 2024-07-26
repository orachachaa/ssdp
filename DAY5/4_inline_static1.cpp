// 4_inline_static1

// Sample.h
class Sample
{
public:
	void foo();

	// 아래 코드는 definition 이 아닙니다.
	// declaration 입니다.
	// 일반 전역변수의 "extern int data" 의미
	static int data;
};


// Sample.cpp
#include "Sample.h"

// static 멤버 데이타는 "결국 전역변수 입니다."
// => 소스에 "definition" 이 있어야 합니다.
int Sample::data = 0;  

void Sample::foo() 
{
}