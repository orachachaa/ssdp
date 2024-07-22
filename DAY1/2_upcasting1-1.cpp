// 2_upcasting1-1.cpp
#include <iostream>

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
	Animal a;
	Dog    d;

//	Animal* p = &d;
	Animal* p = &a;

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
	Dog* pdog2 = dynamic_cast<Dog*>(p);

	std::cout << pdog2 << std::endl;
}











