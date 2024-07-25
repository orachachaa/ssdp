#include <iostream>

int main()
{
	// 문자열 배열 과 포인터 차이
	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1 = "abcd";
	const char* sp2 = "abcd";

	// 아래 결과 예측해 보세요.
	// => 같은 주소? 다른 주소 ?
	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}