// ����
class AAA
{
public:
	static int data;
	typedef int dword;
};
int AAA::data = 0;

int* p = 0;

template<typename T>
void foo(T a)
{
	// �Ʒ� �ڵ带 ���� * �� �ǹ̸� �����غ�����
	AAA::data*  p;
	AAA::dword* p;
}