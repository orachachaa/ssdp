class AAA; // incomplete type ( �ҿ����� Ÿ�� )
			// ��򰡿� �ִٰ� �����Ϸ��� �˰� ������
			// ��Ȯ�� ����� �˼� ���� Ÿ��

AAA* p; // ok. incomplete type �� ������ ������ ����
//AAA  a; // error. ��ü ������ �ȵ�

class Cursor
{
public:
	inline static int data = 0; // ok

//	inline static Cursor c; // error

	static Cursor c;  
};
inline Cursor Cursor::c;   // ok. �̷��� �ϸ� ����� ���԰���
							// complete type

int main()
{

}