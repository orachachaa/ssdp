﻿#include <iostream>
#include <vector>
#include "IGraph.h"

#define USING_GUI
#include "cppmaster.h"

// Subject : 관찰의 대상(Table)의 기반 클래스
class Subject
{
	std::vector<IGraph*> v;
public:
	Subject()
	{
		// #1. 약속된 폴더에 있는 모든 DLL 을 찾아야 합니다.
		// => "ec_enum_files" 의 3번째 인자는 반드시 인자가 2개인 함수이어야 합니다.
		ec_enum_files("C:\\GRAPH", "*.dll", load_module, this);
	}

	bool load_module(const std::string& dllname, void* param)
	{

		return true;
	}



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





