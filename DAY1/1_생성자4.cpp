// protected 생성자의 의미
// => 자신의 객체는 만들수 없지만( 추상 적인 개념(abstract) 을 나타내는 클래스)
//    파생 클래스의 객체는 만들수 있도록(구체적 개념(concrete) 을 나타내는 클래스)

class Animal
{
//public:		// 1, 2 모두 에러 아님
//private:		// 1, 2 모두 에러

protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}	
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// 1. error
	Dog    d;	// 2. ok 
}



