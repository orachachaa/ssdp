#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거(순회)
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행
template<typename T>
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override
	{
		e *= 2;
	}
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override
	{
		std::cout << e << std::endl;
	}
};

template<typename T>
struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

template<typename T>
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list;

	void accept(IVisitor<T>* visitor) override
	{
		for (auto& e : *this)
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	TwiceVisitor<int> tv;
	s.accept(&tv);

	//ShowVisitor<int> sv;
	//s.accept(&sv);
}
