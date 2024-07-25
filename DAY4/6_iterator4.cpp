#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// #1. 반복자 인터페이스 : 모든 반복자가 지켜야 하는 규칙
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T    next() = 0;
	virtual ~IIterator() {}
};

// #2. 컨테이너(컬렉션)인터페이스
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//----------------------
// #3. slist 의 iterator 만들기
// => 핵심 : 1번째 요소를 가리키는 포인터를 가지고 있다가
//          약속된 방식대로만 이동, 요소접근  할수 있으면 됩니다.
template<typename T> 
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}


	// 규칙대로 이동하면 됩니다.
	T next() override
	{
		T tmp = current->data;

		current = current->next;

		return tmp;
	}

	bool hasNext() override
	{
		return current != nullptr;
	}
};
//----------------------------------------




// #4. 모든 컨테이너는 약속된 방식대로 반복자를 꺼낼수 있어야 합니다.
template<typename T> 
struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IIterator<T>* iterator() override 
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}

}
