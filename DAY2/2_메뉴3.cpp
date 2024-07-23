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

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}
	void add(MenuItem* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();
			for (int i = 0; i < v.size(); i++) {
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";
			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) break;

			if (cmd < 1 || cmd > sz + 1)
			{
				std::cout << "Invalid Input\n";
				_getch();
				continue;
			}

			v[cmd - 1]->command();
		}
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 51);

	PopupMenu pm("오늘의 점심메뉴");

	pm.add(&m1);
	pm.add(&m2);

	pm.command();
}




