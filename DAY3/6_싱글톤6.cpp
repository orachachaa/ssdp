// 1�������ؿ�����.
// 7_�̱���1 - 123 page
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

// Mouse Ŭ������ Cursoró�� ���� ����� �̱��� ���� ����ϰ� �ʹ�.
class Mouse : public Singleton<Mouse>
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();
}








