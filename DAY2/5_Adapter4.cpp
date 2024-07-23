#include <iostream>
#include <list>
#include <vector>
#include <deque>

// �ذ�å #1. private ���

// => ������ ���� ������ ( ��� Ŭ���� �Լ��� �Ļ�Ŭ���������������δ� ��� )
//    �������̽��� ���� ���� �ʰڴ�( �ܺ� �������� �ʰڴٴ� ��)

template<typename T>
//class stack : public  std::list<T>
class stack   : private std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop() { std::list<T>::pop_back(); }
	T& top() { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(30);	// error. private ����̹Ƿ�
						// push_front �� private ���
}
