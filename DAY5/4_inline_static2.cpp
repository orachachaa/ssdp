// Sample.h
class Sample
{
public:
	void foo();

	static int data;
};

//int Sample::data = 0;	// �ҽ� 2�� �̻󿡼� include �ϸ�
					    // �ߺ����� ����

inline int Sample::data = 0; // 2���̻󿡼� �����ص� ok. 
							 // class �ȿ� �ٷ� inline ���� �͵� ���
							 // ��������..


// Sample.cpp
#include "Sample.h"


void Sample::foo()
{
}