#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// #1. �ݺ��� �������̽� : ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T    next() = 0;
	virtual ~IIterator() {}
};

// #2. �����̳�(�÷���)�������̽�
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//----------------------
// #3. slist �� iterator �����
// => �ٽ� : 1��° ��Ҹ� ����Ű�� �����͸� ������ �ִٰ�
//          ��ӵ� ��Ĵ�θ� �̵�, �������  �Ҽ� ������ �˴ϴ�.
template<typename T> 
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}


	// ��Ģ��� �̵��ϸ� �˴ϴ�.
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




// #4. ��� �����̳ʴ� ��ӵ� ��Ĵ�� �ݺ��ڸ� ������ �־�� �մϴ�.
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
