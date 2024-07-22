// edit3.cpp  - edit1.cpp ����

#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� �ڵ带 �и��ϴ� 2���� ���
// 1. �����Լ��� �и� - edit2.cpp
// 2. �ٸ� Ŭ������ �и� - edit3.cpp

// Validation ��å�� ������ Ŭ������ �и��Ѵ�.
// => ��ü �����ؾ� �ϹǷ� 
// => �������̽��� ���� ����

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
};

// �ֹ� ��� ��ȣ : 901    1      [Ȯ�ι�ư]



class Edit
{
	std::string data;
	
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; }

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (val == nullptr || val->is_complete(data)) ) break;

//			if ( isdigit(c) )
			if ( val == nullptr || val->validate(data, c) ) // Validation �� �ٸ� Ŭ������ ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


