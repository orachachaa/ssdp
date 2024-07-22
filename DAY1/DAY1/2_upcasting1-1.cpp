// 2_upcasting1-1.cpp
#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {}  // 가상 소멸자(다음시간에 설명)
};
class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog    d;

	Animal* p = &d;
//	Animal* p = &a;

	// static_cast : 컴파일러에게 Dog* 처럼 생각해 달라고 요청하는 것
	//			     컴파일 시간에 동작, 오버헤드 없음.
	//			     객체가 정말 Dog 인지, 컴파일러는 조사할수 없음. 
	//			     단, 객체가 Dog 가 아니라도 성공. 
	//				 Dog 객체가 아니라면 개발자가 책임져야 합니다.
	Dog* pdog = static_cast<Dog*>(p);

	std::cout << pdog << std::endl; 

	if (pdog != nullptr)
	{
//		pdog->color = 10;	// 버그!!!!
							// pdog 가 0 이 아니지만 Dog 가 아닌 Animal 객체
							// 잘못된 코드, 개발자 책임
							// 확신이 있을때만 static_cast 사용해야 합니다
	}

	// #2. dynamic_cast : 실행시간 캐스팅
	//					  실행할때, p가 가리키는 곳이 Dog 인지 조사후 캐스팅
	//					  Dog 객체가 아닌 경우 0 반환

	// 단, dynamic_cast 를 사용하려면 "반드시 1개 이상의 가상함수" 가 있어야 합니다.
	// => 타입의 정보를 "가상함수테이블"에 저장하므로
	// => 가상함수가 있는 타입을 "다형형식(polymorphic type)" 이라고 합니다.
	// => 현실적으로 상속을 사용하면 거의 대부분 "1개이상의 가상함수"는 있게됩니다.
	//    (가상 소멸자 때문에)
	Dog* pdog2 = dynamic_cast<Dog*>(p);

	std::cout << pdog2 << std::endl;

	// dynamic_cast 는 "실행시간 조사" 이므로 성능저하가 있습니다.
	// 프로그램 개발시 p가 가리키는 곳이 Dog 라는 확신이 있으면
	// static_cast 로하세요

	// 확신이 없다면 "dynamic_cast" 로 조사해도 되지만
	// => dynamic_cast 를 사용하면 나쁜 디자인 입니다.
	// => 디자인 자체를 변경해야 합니다. 오후의 핵심 내용
}











