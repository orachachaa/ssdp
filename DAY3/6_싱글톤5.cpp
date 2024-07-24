#include <iostream>
#include <mutex>

// RAII Idioms 

// 자원의 할당/해지는 반드시 "생성자/소멸자"에 의존해야 합니다.
template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
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
		lock_guard<std::mutex> g(mtx);

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





