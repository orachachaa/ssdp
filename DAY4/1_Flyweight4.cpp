#include <stdio.h>

int main()
{
	// ���ڿ� �迭 vs ���ڿ� ������
	char sa[] = "abcd";
	char* sp = "abcd";			// sp�� char*��� runtion error
								// C���� ok, C++������ ����
//	const char* sp = "abcd";	// sp�� const char*��� compile time error

	*sa = 'X';
//	*sp = 'X';

	printf("main finish\n");
}