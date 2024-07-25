// SampleGraph.cpp
#include "IGraph.h"
#include <iostream>

// PieGraph 복사해오세요
// 이름을 "SampleGraph" 로 변경하세요
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

// 시작 버튼 => "Developer Command..." 실행
// 
// cl SampleGraph.cpp /LD   로 빌드후에

// C://Graph  라는 폴더를 만들고 SampleGraph.dll 을 복사해 놓으세요