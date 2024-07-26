// 3_main.cpp, 3_variable.cpp, variable.h 만드세요

// 3_main.cpp
#include "variable.h"

int main()
{
	g = 10;
}


// #1. 전역변수는 "소스파일(.cpp, .c)" 에 만들어야 합니다.
// 
// #2. 헤더 파일에서 "extern int g" 처럼 선언을 하면
//     다른 소스파일에서 접근 가능합니다. 

// #3. 전역변수 자체를 헤더에 정의(definition) 하면 
//     중복정의에러가 발생합니다.

// #4. 