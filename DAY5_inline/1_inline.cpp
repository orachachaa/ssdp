// 아래 코드를 godbolt.org 에 왼쪽에 넣어 보세요

       int add1(int a, int b) { return a + b;}
inline int add2(int a, int b) { return a + b;}

int main()
{
    int n1 = add1(1, 2);
    int n2 = add2(1, 2);
}
