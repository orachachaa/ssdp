// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

#define MAKE_SINGLETON(classname)						\
private:												\
	classname() {}										\
	classname(const classname& c) = delete;				\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& get_instance()					\
	{													\
		static classname instance;						\
		return instance;								\
	}

class Cursor
{
	MAKE_SINGLETON(Cursor);
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








