// 7 page

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Dog d;
	Dog* p1 = &d; // ok
	
//	int* p2 = &d; // error
	
	// 핵심 #1. 파생클래스 객체의 주소를 "기반 클래스 포인터" 에 담을수 있다.
	// => upcasting 이라고 합니다.
	// => 이유는 "메모리 그림"을 생각해 보세요
	Animal* p3 = &d; // ok

}











