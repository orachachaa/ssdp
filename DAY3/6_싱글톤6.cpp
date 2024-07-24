#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
//        (�ű��ϰԵ� ��޵Ǵ� ���ø� ���� ?)

// => ��� Ŭ���� ���鶧 �Ļ� Ŭ���� �̸��� ����Ҽ� �ְ� �ϴ� ����
// => ��� Ŭ������ ���ø����� �����, �Ļ� Ŭ���� ���鶧 �ڽ��� �̸���
//    ��� Ŭ���� ���ø� ���ڷ� �����ϴ� ��

// �������� ������ ��ũ���̾��µ�, ������ ���� �߿��� ���
// =>C++20 �� ���� ���̺귯���� �̱�� ���.


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton& c) = delete;
	Singleton& operator=(const Singleton&) = delete;

	inline static T* sinstance = nullptr;
	inline static std::mutex mtx;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new T;

		return *sinstance;
	}
};

// Mouse Ŭ������  Cursoró�� ���� ����� �̱��� ���� ����ϰ� �ʹ�.

class Mouse : public Singleton< Mouse >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}





// github.com/aosp-mirror  <== "�ȵ���̵� ���¼ҽ�"

// system platform core �������丮 ����

// libutils/include/utils ����   singleton.h ���� ������
