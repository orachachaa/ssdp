//1_관찰자패턴1 - 98 page
#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void update(int data, Subject* sender) = 0;
	virtual ~IGraph() {}
};

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) { }
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->update(data, this);
	}
};

class Table : public Subject
{
	int value; // table 의 data 값
	int arr[4] = { 1,2,3,4 };
public:
	int* get_data() { return arr; }

	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int hint, Subject* sender) override
	{
		Table* table = static_cast<Table*>(sender);
		int* data = table->get_data();

		std::cout << "Bar Graph : ";

		for (int i = 0; i < hint; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int hint, Subject* sender) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < hint; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





