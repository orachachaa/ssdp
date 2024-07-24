// 1번복사해오세요.
// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard() { mtx.unlock(); }
};

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor&) = delete;

	inline static Cursor* sinstance = nullptr;
	inline static std::mutex mtx;
public:
	static Cursor& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);
		//lock_guard<std::mutex> g(mtx);
		//mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

		//mtx.unlock();

		return *sinstance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








