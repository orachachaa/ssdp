#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() const { return title; }
	virtual void command() = 0;
};

class MenuItem : public BaseMenu {
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}


	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}
	void add(BaseMenu* m) { v.push_back(m); }

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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");
	PopupMenu* pm2 = new PopupMenu("해상도변경");

	root->add(pm1);
	//root->add(pm2);
	pm1->add(pm2);
	root->add(new MenuItem("자동설정", 11));

	pm1->add(new MenuItem("Red", 21));
	pm1->add(new MenuItem("Green", 22));
	pm1->add(new MenuItem("Blue", 23));
	pm1->add(new MenuItem("White", 24));

	pm2->add(new MenuItem("HD", 31));
	pm2->add(new MenuItem("FHD", 32));
	pm2->add(new MenuItem("UHD", 33));

	root->command();
}




