#include <iostream>
#include <vector>

class Subject;	// 클래스 전방선언
				// 다른 파일에 있거나, 소스 아래 부분에 있는
				// 클래스라도 포인터 타입은 사용할수 있게

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
		for (auto p : v)
			p->update(data, this);
	}
};


class Table : public Subject
{
	int value;
	
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
	void update(int n, Subject* sender) override
	{
		// Table이 변했다고 통보가 왔으므로
		// Table에 접근해서 멤버 함수를 통해서 데이타를 얻어 온다.
		
		Table* table = static_cast<Table*>(sender);

		int* data = table->get_data();

		// data 를 사용해서 그린다.!!

		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int n, Subject* sender) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
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





