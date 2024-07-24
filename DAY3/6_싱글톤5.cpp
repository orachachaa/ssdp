// 1�������ؿ�����.
// 7_�̱���1 - 123 page
#include <iostream>
#include <mutex>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

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








