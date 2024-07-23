#include <iostream>
#include <list>
#include <vector>
#include <deque>

// private ���
template<typename T> class stack
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(30);
}
