#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::bind, std::function
using namespace std::placeholders;



class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }


	virtual void command() = 0;
};







class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	~PopupMenu()
	{
		for (auto m : v)
			delete m;
	}
	
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
};


class MenuItem : public BaseMenu
{
	int id;

	using HANDLER = std::function<void()>;

	std::vector<HANDLER> handler_vector;

public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr)
		: BaseMenu(title), id(id)
	{
		if (h != nullptr)
			handler_vector.push_back(h);
	}

	void add_handler(HANDLER h) { handler_vector.push_back(h); }


	void command()
	{
		for (auto f : handler_vector)
			f();
	}
};
//-------------------------------------
void f0() { std::cout << "f0\n"; _getch(); }
void f1(int id) { std::cout << "f1 : " << id << "\n"; _getch(); }
void f2(int a, int b) { std::cout << "f2\n"; _getch(); }

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");
	PopupMenu* pm2 = new PopupMenu("해상도변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add(new MenuItem("Red", 21, &f0));
	pm1->add(new MenuItem("Green", 22, []() { std::cout << "lambda\n"; }));

	pm2->add(new MenuItem("HD", 31, std::bind(&f1, 31)));
	pm2->add(new MenuItem("FHD", 32, std::bind(&f1, 32)));

	root->command();


}
