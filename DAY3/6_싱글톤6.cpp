#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
//        (신기하게도 언급되는 템플릿 패턴 ?)

// => 기반 클래스 만들때 파생 클래스 이름을 사용할수 있게 하는 패턴
// => 기반 클래스를 템플릿으로 만들고, 파생 클래스 만들때 자신의 이름을
//    기반 클래스 템플릿 인자로 전달하는 것

// 예전에는 가벼운 테크닉이었는데, 지금은 아주 중요한 기술
// =>C++20 의 많은 라이브러리가 이기술 사용.


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton& c) = delete;
	Singleton& operator=(const Singleton&) = delete;

	inline static T* sinstance = nullptr;
	inline static std::mutex mtx;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new T;

		return *sinstance;
	}
};

// Mouse 클래스도  Cursor처럼 힙에 만드는 싱글톤 모델을 사용하고 싶다.

class Mouse : public Singleton< Mouse >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}





// github.com/aosp-mirror  <== "안드로이드 오픈소스"

// system platform core 레포지토리 선택

// libutils/include/utils 에서   singleton.h 열어 보세요
