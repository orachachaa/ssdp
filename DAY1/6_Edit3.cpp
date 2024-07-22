// edit3.cpp  - edit1.cpp 복사

#include <iostream>
#include <string>
#include <conio.h>

// 변하는 코드를 분리하는 2가지 방법
// 1. 가상함수로 분리 - edit2.cpp
// 2. 다른 클래스로 분리 - edit3.cpp

// Validation 정책을 별도의 클래스로 분리한다.
// => 교체 가능해야 하므로 
// => 인터페이스를 먼저 설계

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
};

// 주민 등록 번호 : 901    1      [확인버튼]



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
			if ( val == nullptr || val->validate(data, c) ) // Validation 을 다른 클래스에 위임
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


