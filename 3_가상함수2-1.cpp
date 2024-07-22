﻿#include <iostream>

class Base
{
public:
	//~Base() {}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	//Derived d;
	//delete p;

	//Base* p = new Derived;
	//delete p;

	Base* p = new Derived;
	delete p;
}	
