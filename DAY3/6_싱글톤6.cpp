// 1번복사해오세요.
// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

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

// Mouse 클래스도 Cursor처럼 힙에 만드는 싱글톤 모델을 사용하고 싶다.
class Mouse : public Singleton<Mouse>
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();
}








