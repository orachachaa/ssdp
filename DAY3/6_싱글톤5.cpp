#include <iostream>
#include <mutex>

// RAII Idioms 

// �ڿ��� �Ҵ�/������ �ݵ�� "������/�Ҹ���"�� �����ؾ� �մϴ�.
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
		{
			std::lock_guard<std::mutex> g(mtx);

//			lock_guard<std::mutex> g(mtx);  // 1. g �� �����ڿ��� mtx.lock()
											// 2. g �� �ı��ɶ� �Ҹ��ڿ��� mtx.unlock()
											// => ���ܰ� �߻��ص� ����������
											//    �����ϰ� �ı�, �Ҹ��� ȣ���
											//	  "stack unwinding" ����
			//mtx.lock();

			if (sinstance == nullptr)
				sinstance = new Cursor;

			//mtx.unlock();
		}
		return *sinstance;
	}

};



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}





