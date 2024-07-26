class AAA; // incomplete type ( 불완전한 타입 )
			// 어딘가에 있다고 컴파일러가 알게 되지만
			// 정확한 모양을 알수 없는 타입

AAA* p; // ok. incomplete type 의 포인터 생성은 가능
//AAA  a; // error. 객체 생성은 안됨

class Cursor
{
public:
	inline static int data = 0; // ok

//	inline static Cursor c; // error

	static Cursor c;  
};
inline Cursor Cursor::c;   // ok. 이렇게 하면 헤더에 포함가능
							// complete type

int main()
{

}