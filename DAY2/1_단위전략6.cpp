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

	v.resize(4);	// 4개 크기 메모리 할당

	std::cout << "-----------------" << std::endl;

	v.resize(8);	// 1. 8개 할당
					// 2. 4개 버퍼내용 => 8개 버퍼에 복사
					// 3. 4개 버퍼 제거

	std::cout << "-----------------" << std::endl;
}

// strategy vs policy base design

// => 결국, 클래스가 사용하는 어떤 정책을 "별도의 클래스로 분리해서"
//    교체 할수 있게 하자는 것!!

// strategy			  : interface 를 만들어서 교체 할수 있게
// policy base design : template 인자로 교체


//						  성능						유연성
// strategy				: 가상함수기반. 느리다.		실행시간 교체 가능
// policy base design	: 인라인 치환가능. 빠르다		실행시간 교체 안됨

// Edit e;
// e.set_validate(&v1); // v1 정책을 사용하다가
// e.set_validate(&v2); // v2 정책으로 교체, 즉, 다른 정책으로 교체 가능

// std::vector<int, debug_alloc<int>> v1;
// => v1은 debug_alloc 만 사용가능.
// => 실행할때 다른 할당기로 교체 안됨.