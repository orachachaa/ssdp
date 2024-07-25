#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem;
class PopupMenu;

struct IVisitor
{
	virtual void visit(MenuItem* e) = 0;
	virtual void visit(PopupMenu* e) = 0;
	virtual ~IVisitor() {}
};

struct IAcceptor
{
	virtual void accept(IVisitor* visit) = 0;
	virtual ~IAcceptor() {}
};

class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }
	void set_title(const std::string& s) { title = s; }
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	void accept(IVisitor* visitor)
	{
		visitor->visit(this);
	}

	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	void accept(IVisitor* visitor)
	{
		visitor->visit(this);

		for (auto m : v)
			//visitor->visit(m); // X
			m->accept(visitor);
	}

	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};

class TitleChangeVisitor : public IVisitor
{
	std::string item_tag;
	std::string popup_tag;
public:
	TitleChangeVisitor(const std::string& s1, const std::string& s2)
		: popup_tag(s1), item_tag(s2) {}

	void visit(MenuItem* m) override
	{
		auto s = m->get_title() + item_tag;
		m->set_title(s);
	}
	void visit(PopupMenu* m) override
	{
		auto s = m->get_title() + popup_tag;
		m->set_title(s);
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	TitleChangeVisitor v(" >", " #");
	root->accept(&v);

	root->command();
}




