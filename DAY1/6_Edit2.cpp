// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// 핵심
// => Validation 정책은 사용자가 변경할수 있어야 한다.
// => Edit 는 라이브러리 클래스 이므로 Edit 내부 코드를 사용자가 변경할수는 없다

// 방법 #1. 변해야 하는 것을 "가상함수"로 분리
// => 문제의 해결(validation 정책 변경) 을 위해 
// => "template method" 패턴을 적용한것!

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

//			if (isdigit(c))		// 직접 validation
			if (validate(c))	// 가상함수에 의존
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};
// 위처럼 설계한 의도!!
// => Validation 정책을 변경하려면
// => 파생 클래스를 만들어서 "약속된 가상함수(validate) 를 override 하라는것
// => 기존 코드의 수정이 아닌 기존 코드(라이브러리)의 확장

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


