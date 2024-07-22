// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

struct IValidator {
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
};

class Edit
{
	std::string data;
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; }
	std::string get_data()
	{
		data.clear();

		while (1) {
			char c = _getch();
			
			if (c == 13 && (val == nullptr || val->is_complete(data))) break;
			
			//if (isdigit(c)) {
			if (val == nullptr || val->validate(data, c)) {
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

class LimitDigitValidator : public IValidator {
	int limit;
public:
	LimitDigitValidator(int value = 9999) : limit(value) {}
	bool validate(const std::string& s, char c) override
	{
		return isdigit(c) && (limit == 9999 || s.size() < limit);
	}

	bool is_complete(const std::string& s) override
	{
		return s.size() == limit;
	}
};

int main()
{
	Edit e;

	LimitDigitValidator v(5);
	e.set_validator(&v);

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}
