// edit3.cpp  - edit1.cpp 복사

#include <iostream>
#include <string>
#include <conio.h>

// 변하는 코드를 분리하는 2가지 방법
// 1. 가상함수로 분리 - edit2.cpp
// 2. 다른 클래스로 분리 - edit3.cpp

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


