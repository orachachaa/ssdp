#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. STL 에는 linked list 가 이미 있습니다.
// 2. 그런데, 사용자가 stack 을 요구 합니다.

// list 의 함수이름을 스택처럼 보이게 변경해 봅시다.
template<typename T> 
class stack : public std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(e); }
	T&   top()            { return std::list<T>::back(e);}
};

int main()
{
	stack<int> s;
	s.push(10);
}
