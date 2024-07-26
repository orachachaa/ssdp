// 아래 코드를 godbolt.org 에 왼쪽에 넣어 보세요

// 치환 결과 확인하려면
// msvc 컴파일러에 "-Ob1" 옵션 적용하세요

       int add1(int a, int b) { return a + b;}
inline int add2(int a, int b) { return a + b;}

int main()
{
    int n1 = add1(1, 2);
    int n2 = add2(1, 2);

    // 아래 코드가 없으면 "add2" 자체는 별도의 기계어로 생성안되지만
    // 아래 코드 있으면 "add2" 자체의 기계어도 생성되어야 합니다.
    int(*f)(int, int) = &add2;
}
