// 참고
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
	// 아래 코드를 보고 * 의 의미를 생각해보세요
	AAA::data*  p;
	AAA::dword* p;
}