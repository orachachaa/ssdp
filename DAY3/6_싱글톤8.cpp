#include <iostream>

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
	MAKE_SINGLETON(Cursor)
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}




