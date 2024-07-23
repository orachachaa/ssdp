#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #2. 상속이 아닌 포함

// private 상속 : list 에 가상함수가 있었다면 override 할수 있다.
// 포함         : list 에 가상함수가 있어도 override 할수 없다.

// 현재 예제는 포함이 좋다. (list 에 가상함수 없다)


template<typename T>
class stack 
{
	std::list<T> c;
public:
	void push(const T& e)   { c.push_back(e); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

//	s.push_front(30);	// error. push_front 는 없다
}
