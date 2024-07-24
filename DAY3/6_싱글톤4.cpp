#include <iostream>
#include <mutex>
// 스레드 안정성
// => 멀티스레드 환경에서도 오직 한개만 만들어 지도록

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
		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

		mtx.unlock();

		return *sinstance;
	}

};



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}





