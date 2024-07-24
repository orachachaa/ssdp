#include <iostream>
#include <mutex>


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

		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};

// Mouse Ŭ������  Cursoró�� ���� ����� �̱��� ���� ����ϰ� �ʹ�.

class Mouse
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}





