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

// #3. 모든 컨테이너는 accept 가 있어야 한다.
template<typename T> 
struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

// #4. STL 은 방문자 패턴을 사용하지 않습니다.
//     std::list 를 확장해서 방문자 패턴을 추가해 봅시다.
template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:

	// 생성자 상속 문법 : 기반 클래스의 모든 생성자 모양을 
	//					 파생클래스 객체 생성시에도 동일하게 사용할수 있도록해달라

	using std::list<T>::list;  // using 클래스이름::생성자이름

	void accept(IVisitor<T>* visitor) override
	{
		for (auto& e : *this)    // *this 의 의미를 생각해 보세요
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.accept(&tv);	  


	ShowVisitor<int> sv;  
	s.accept(&sv);	  
}





