#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter 패턴 + Policy Base Design 적용!!

template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

#include <stack> // C++ 표준의 stack 이 위 코드와 동일합니다.

int main()
{
//	std::stack<int,

	stack<int, std::vector<int> > s1;
	stack<int, std::list<int> >   s2;

	stack<int>   s;
	s.push(10);
}
