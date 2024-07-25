#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// #1. �ݺ��� �������̽� : ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ
// => �� ������ ����, �Լ� �̸��� ������ �������.



// #2. �����̳�(�÷���)�������̽�
// => �Լ��̸��� ������ �������
// => begin(), end()


//----------------------
// #3. slist �� iterator �����

template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// ��� ���ٰ� �̵� ����� �迭(raw pointer) 
	// �� ��ȸ �ϴ� ����� �����ϰ�
	// => ++, *
	// => C++ �� ������ �����ǰ� �ȴ�.!

	// ���� : ++++i �� �Ƿ��� ��ȯ���� �ڽ��� ������
	inline slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	
	inline T& operator*() { return current->data; }

	// ==, != �� �����ϰ�

	inline bool operator==(const slist_iterator<T>& other)
	{
		return current == other.current;
	}
	inline bool operator!=(const slist_iterator<T>& other)
	{
		return current != other.current;
	}

};
//----------------------------------------

template<typename T>
struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin() {	return slist_iterator<T>(head);	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto first = s.begin();
	auto last = s.end();

	while (first != last)
	{
		std::cout << *first << std::endl; // 40
		++first;
	}

}

