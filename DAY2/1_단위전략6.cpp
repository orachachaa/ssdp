#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기 만들기
// 1. 반드시 template 일 필요는 없지만, 다양한 타입에 사용하기 위해
//    대부분 템플릿으로 작성

template<typename T>
class debug_alloc
{
public:

};



int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<int> > v

	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;
}
