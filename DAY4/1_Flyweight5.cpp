#include <iostream>

int main()
{
	// ���ڿ� �迭 vs ���ڿ� ������
	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1 = "abcd";
	const char* sp2 = "abcd";

	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}