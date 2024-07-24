#include <iostream>

// 유일한 객체가 힙에 있는 모델

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor& c) = delete; 
	Cursor& operator=(const Cursor&) = delete;

	inline static Cursor* sinstance = nullptr;
public:
	static Cursor& get_instance()
	{
		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}





