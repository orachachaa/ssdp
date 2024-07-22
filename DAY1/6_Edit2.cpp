// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// �ٽ�
// => Validation ��å�� ����ڰ� �����Ҽ� �־�� �Ѵ�.
// => Edit �� ���̺귯�� Ŭ���� �̹Ƿ� Edit ���� �ڵ带 ����ڰ� �����Ҽ��� ����

// ��� #1. ���ؾ� �ϴ� ���� "�����Լ�"�� �и�
// => ������ �ذ�(validation ��å ����) �� ���� 
// => "template method" ������ �����Ѱ�!

class Edit
{
	std::string data;
public:

	virtual bool validate(char c)
	{
		return true;
	}
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

//			if (isdigit(c))		// ���� validation
			if (validate(c))	// �����Լ��� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};
// ��ó�� ������ �ǵ�!!
// => Validation ��å�� �����Ϸ���
// => �Ļ� Ŭ������ ���� "��ӵ� �����Լ�(validate) �� override �϶�°�
// => ���� �ڵ��� ������ �ƴ� ���� �ڵ�(���̺귯��)�� Ȯ��

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;

//	AddressEdit e2;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


