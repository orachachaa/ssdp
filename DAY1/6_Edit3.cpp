// edit3.cpp  - edit1.cpp ����

#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� �ڵ带 �и��ϴ� 2���� ���
// 1. �����Լ��� �и� - edit2.cpp
// 2. �ٸ� Ŭ������ �и� - edit3.cpp

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (isdigit(c)) 
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


