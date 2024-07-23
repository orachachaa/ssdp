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

	// 아래 멤버 함수는 "PopupMenu" 에만 필요 하지만
	// "main 코드 처럼 캐스팅없이 사용하려면 BaseMenu" 에도 있어야합니다.
	virtual BaseMenu* submenu(int idx) {}
	virtual void add(BaseMenu* m) {}
};







class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}



	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";

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

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();
		}

	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};



int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");
	PopupMenu* pm2 = new PopupMenu("해상도변경");

	root->add(pm1);
	root->add(pm2);
	root->add(new MenuItem("자동설정", 11));


//	static_cast<PopupMenu*>(root->submenu(0))->add(new MenuItem("Red", 11));

	// 캐스팅 없이 아래 처럼 사용하고 싶다면 어떻게 해야 할까요?
	// => add 가 BaseMenu 에 있어야 합니다.
	root->submenu(0)->add(new MenuItem("Red", 11));


	root->command();
}


