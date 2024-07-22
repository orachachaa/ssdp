// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// 핵심
// => Validation 정책은 사용자가 변경할수 있어야 한다.
// => Edit 는 라이브러리 클래스 이므로 Edit 내부 코드를 사용자가 변경할수는 없다

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


