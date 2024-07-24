﻿// 1번복사해오세요.
// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

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








