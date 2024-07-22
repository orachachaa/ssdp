// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// upcasting 활용 #1. 
	std::vector<Dog*>    v1; // v1 에는 Dog 객체만 저장하겠다는 의도
	std::vector<Animal*> v2; // v2 에는 모든 동물 객체를 저장하겠다는 의도
							 // "동종(Animal 에서 파생된 클래스)을 보관하는 컨테이너 만들기"
}
