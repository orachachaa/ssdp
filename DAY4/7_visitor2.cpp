#include <iostream>
#include <list>
#include <vector>

// #1. 방문자 인터페이스
template<typename T>
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// #2. 실제 Visitor 
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override
	{
		e *= 2;
	}
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override
	{
		std::cout << e << std::endl;
	}
};



int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };


	for (auto& e : s)
		s *= 2;

	TwiceVisitor<int> tv; 
	s.accept(&tv);	  


	ShowVisitor<int> sv;  
	s.accept(&sv);	  
}





