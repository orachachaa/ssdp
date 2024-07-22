// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// GUI widget 인 "edit(textbox)" 를 만드는 것을 생각해 봅시다.

// Edit 는 사용자 입력에 대해서 "유효성(Validation)" 기능이 있어야 합니다.

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

			if (c == 13) break; // enter 입력

			if ( isdigit(c) )  // 값의 유효성(숫자) 검사
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


