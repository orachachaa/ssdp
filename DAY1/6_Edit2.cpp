// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// �ٽ�
// => Validation ��å�� ����ڰ� �����Ҽ� �־�� �Ѵ�.
// => Edit �� ���̺귯�� Ŭ���� �̹Ƿ� Edit ���� �ڵ带 ����ڰ� �����Ҽ��� ����

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


