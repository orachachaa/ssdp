#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list : 모든 요소가 동일타입입니다. 선형 구조입니다.
// menu : 요소의 타입이 다릅니다.     트리 구조입니다.

// 방문자 인터페이스

struct MenuItem;
struct PopupMenu;

struct IVisitor
{
	// 아래 처럼 따로 만들어야, 메뉴 종류에 따라 다르게 동작하게 
	// 만들수 있습니다.
	virtual void visit(MenuItem* e) = 0;
	virtual void visit(PopupMenu* e) = 0;
	virtual ~IVisitor() {}
};

struct IAcceptor
{
	virtual void accept(IVisitor* visitor) = 0;
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
		// 자신을 방문자에 전달하면 된다.
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
	
	// 방문자가 Popup 에 도착했을때
	void accept(IVisitor* visitor)
	{
		// #1. 자신을 방문자에 전달한다.
		visitor->visit(this);

		// #2. 방문자에게 하위 메뉴 전달 하면 안되고
		//     하위 메뉴에 방문자를 "방문" 시켜야 합니다.
		for (auto m : v)
//			visitor->visit(m); // 이렇게 하지말고
			m->accept(visitor);// 이렇게!
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

// 이제 위코드는
// "방문자 패턴의 기본 로직" 을 모두 구현해 놓았습니다.
// => 방문자가 이동할수 있는 방법을 제공
// => 이제 다양한 일을 하는 방문자를 만드세요

class TitleChangeVisitor : public IVisitor
{
	std::string item_tag;
	std::string popup_tag;
public:
	TitleChangeVisitor(const std::string& s1, const std::string& s2)
		: popup_tag(s1), item_tag(s2) {}

	void visit(MenuItem* m) override  {}
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

	// root 안에 있는 모든 메뉴 객체에 대해서 Title 을 변경하고 싶다
	// 방법 #1. iterator 패턴을 적용해서 모든 요소에 접근할수 있게 하고,
	//          각 요소가 어떤 메뉴인지 조사해서 
	//			PopupMenu 라면 title 변경!

	// 방법 #2. visitor 패턴 사용
	TitleChangeVisitor v(" >", "");
	root->accept(&v);


	root->command();

}




