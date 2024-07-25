#include <iostream>

int main()
{
	// 문자열 배열 vs 문자열 포인터
	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1 = "abcd";
	const char* sp2 = "abcd";

	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}