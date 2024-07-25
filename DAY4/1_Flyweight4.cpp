#include <stdio.h>

int main()
{
	// 문자열 배열 vs 문자열 포인터
	char sa[] = "abcd";
	char* sp = "abcd";			// sp가 char*라면 runtion error
								// C언어는 ok, C++에서는 에러
//	const char* sp = "abcd";	// sp가 const char*라면 compile time error

	*sa = 'X';
//	*sp = 'X';

	printf("main finish\n");
}