#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기 만들기
// 1. 반드시 template 일 필요는 없지만, 다양한 타입에 사용하기 위해
//    대부분 템플릿으로 작성

// 2. 반드시 표준 문서에서 약속된 규칙을 지켜야 합니다.
// => 인터페이스로 약속하지 않고(가상함수를 사용하지 않기 위해)
// => 문서화로 약속되어 있습니다
// => allocate, deallocate 가 있어야 합니다.

template<typename T>
class debug_alloc
{
public:
	inline T* allocate(std::size_t size) 
	{ 
		T* p = static_cast<T*>(malloc(sizeof(T) * size)); 
		printf("allocate : %p, %zd\n", p, size);
		return p;
	}

	inline void deallocate(T* p, std::size_t size)
	{ 
		printf("deallocate : %p, %zd\n", p, size);
		free(p); 
	}

	// 위 2개 외에도 아래 3개가 필요 합니다
	// => 관례적인 코드이므로 복사해서 사용하면됩니다.

	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
	using value_type = T;
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
