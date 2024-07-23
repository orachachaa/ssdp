#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem {
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}
	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		_getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 51);

	m1.command();
}




