// ����
class AAA
{
public:
	static int data;
	typedef int dword;
};
int AAA::data = 0;

int p = 0;

template<typename T>
void foo(T a)
{
	// �Ʒ� �ڵ带 ���� * �� �ǹ̸� �����غ�����
	// => ���ϱ� ? ������ ���� ����
//	AAA::data*  p;	// 1. AAA::data �� "��" ����, * �� ���ϱ� ������
//	AAA::dword* p;	// 2. AAA::dword �� "Ÿ��" ����, * �� ������ ������

	// ��, "Ŭ�����̸�::�̸�" ���� �̸���
	// 1. ���ϼ��� �ְ�
	// 2. Ÿ���ϼ��� �ֽ��ϴ�.

	// �Ʒ� �ڵ� �ؼ��� ������
	// dependent name : ���ø� ���� T�� �����ϴ� �̸�
	//					�����Ϸ��� �⺻������ "��"���� �ؼ��Ѵ�

//	T::dword* p2;		// error, ������ �ؼ��ϹǷ� ���ϱ�� �ؼ�
						// p2�� ã���� ����. �׷��� ����

	typename T::dword* p2; // ok
							// dependent name �� Ÿ������ �ؼ��� �޶�°�
}
int main()
{

}


