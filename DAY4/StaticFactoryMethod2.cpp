#include <iostream>

class Base
{
public:
	Base() {}
	template<typename T>
	static T* create()
	{
		T* p = new T;
		p->init();
		return p;
	}
	virtual void init() { std::cout << "Base init\n"; }
};

class Derived : public Base
{
public:
	void init() override { std::cout << "Derived init\n"; }
};

int main()
{
	Base* p = Base::create<Derived>();
}