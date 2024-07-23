#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter ���� + Policy Base Design ����!!

template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

#include <stack> // C++ ǥ���� stack �� �� �ڵ�� �����մϴ�.

int main()
{
//	std::stack<int,

	stack<int, std::vector<int> > s1;
	stack<int, std::list<int> >   s2;

	stack<int>   s;
	s.push(10);
}
