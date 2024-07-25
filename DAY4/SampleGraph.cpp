// SampleGraph.cpp
#include "IGraph.h"
#include <iostream>

// PieGraph �����ؿ�����
// �̸��� "SampleGraph" �� �����ϼ���
class SampleGraph : public IGraph
{
public:
	void update(int hint, Subject* sender) override
	{
		std::cout << "Sample Graph : ";

		for (int i = 0; i < hint; i++)
			std::cout << "#";

		std::cout << std::endl;
	}
};

extern "C" __declspec(dllexport)
IGraph* create()
{
	return new SampleGraph;
}

// ���� ��ư => "Developer Command..." ����
// 
// cl SampleGraph.cpp /LD   �� �����Ŀ�

// C://Graph  ��� ������ ����� SampleGraph.dll �� ������ ��������