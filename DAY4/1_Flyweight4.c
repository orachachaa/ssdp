#include <stdio.h>

int main()
{
	// ���ڿ� �迭 vs ���ڿ� ������
	// ���ڿ� �迭   : ���ڿ� ����
	// ���ڿ� ������ : ���ڿ� ���� ����, �ٸ� ���ڿ��� ����Ű�� ��
//	char sa[] = "abcd";
//	char* sp = sa;

	//----------------
	char sa[] = "abcd";
	char* sp = "abcd";


	*sa = 'X'; // ok
//	*sp = 'X'; // runtime error

	printf("main finish\n");
}

// �ҽ� Ȯ���� .c �� �� ������