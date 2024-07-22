// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

//void NewYear(Dog* p) // 인자로 Dog 객체만 받겠다는 의도
void NewYear(Animal* p) // 인자로 모든 동물 객체를 받겠다는 의도
{
	++(p->age); 	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











