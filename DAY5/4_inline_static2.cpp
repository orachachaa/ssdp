// Sample.h
class Sample
{
public:
	void foo();

	static int data;
};

//int Sample::data = 0;	// 소스 2개 이상에서 include 하면
					    // 중복정의 에러

inline int Sample::data = 0; // 2곳이상에서 포함해도 ok. 
							 // class 안에 바로 inline 적는 것도 허용
							 // 다음예제..


// Sample.cpp
#include "Sample.h"


void Sample::foo()
{
}