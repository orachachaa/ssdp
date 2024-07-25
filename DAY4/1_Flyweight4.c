#include <stdio.h>

int main()
{
	// 문자열 배열 vs 문자열 포인터
	// 문자열 배열   : 문자열 소유
	// 문자열 포인터 : 문자열 소유 안함, 다른 문자열을 가리키는 것
//	char sa[] = "abcd";
//	char* sp = sa;

	//----------------
	char sa[] = "abcd";
	char* sp = "abcd";


	*sa = 'X'; // ok
//	*sp = 'X'; // runtime error

	printf("main finish\n");
}

// 소스 확장자 .c 로 해 보세요