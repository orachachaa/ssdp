#include <iostream>
#include <list>
#include <vector>

// #1. �湮�� �������̽�
template<typename T>
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// #2. ���� Visitor 
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

// #3. ��� �����̳ʴ� accept �� �־�� �Ѵ�.
template<typename T> 
struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

// #4. STL �� �湮�� ������ ������� �ʽ��ϴ�.
//     std::list �� Ȯ���ؼ� �湮�� ������ �߰��� ���ô�.
template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
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





