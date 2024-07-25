#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// #1. 반복자 인터페이스 : 모든 반복자가 지켜야 하는 규칙
// => 를 만들지 말고, 함수 이름을 문서로 약속하자.



// #2. 컨테이너(컬렉션)인터페이스
// => 함수이름을 문서로 약속하자
// => begin(), end()


//----------------------
// #3. slist 의 iterator 만들기

template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// 요소 접근과 이동 방법을 배열(raw pointer) 
	// 을 순회 하는 방법과 동일하게
	// => ++, *
	// => C++ 은 연산자 재정의가 된다.!

	// 참고 : ++++i 가 되려면 반환값은 자신을 참조로
	inline slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	
	inline T& operator*() { return current->data; }

	// ==, != 도 가능하게

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

