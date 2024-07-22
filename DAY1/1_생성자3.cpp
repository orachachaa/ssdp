// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};

class Student : Person {
	int id;
public:
	Student(const std::string& name, int age, int id)
		: Person(name, age), id(id) {}
};

int main()
{
//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	Student s("kim", 15, 11);
}


