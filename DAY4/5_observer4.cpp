// 3번 복사해오세요
//1_관찰자패턴1 - 98 page
#include <iostream>
#include <vector>

#include "IGraph.h"

#define USING_GUI
#include "cppmaster.h"

class Subject
{
	std::vector<IGraph*> v;
public:
	Subject()
	{
		ec_enum_files("C:\\Graph", "*.dll", load_module, this);
	}
	
	static int load_module(std::string dllname, void* param)
	{
		std::cout << dllname << std::endl;

		void* addr = ec_load_module(dllname);
		using F = IGraph * (*)();

		F f = (F)ec_get_function_address(addr, "create");
		IGraph* g = f();
		//attach(g);
		static_cast<Subject*>(param)->attach(g);

		return 1;
	}

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





