// �Ʒ� �ڵ带 godbolt.org �� ���ʿ� �־� ������

// ġȯ ��� Ȯ���Ϸ���
// msvc �����Ϸ��� "-Ob1" �ɼ� �����ϼ���

       int add1(int a, int b) { return a + b;}
inline int add2(int a, int b) { return a + b;}

int main()
{
    int n1 = add1(1, 2);
    int n2 = add2(1, 2);

    // �Ʒ� �ڵ尡 ������ "add2" ��ü�� ������ ����� �����ȵ�����
    // �Ʒ� �ڵ� ������ "add2" ��ü�� ��� �����Ǿ�� �մϴ�.
    int(*f)(int, int) = &add2;
}
