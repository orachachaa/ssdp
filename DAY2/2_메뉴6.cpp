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
};





int main()
{
	// 아래 코드를 보고, 각 메뉴 객체의 포함관계를 생각해 보세요
	// => "TREE" 자료구조의 모양을 가지게 됩니다.
	// => 객체의 포함 관계가 tree 구조로 만들어 지게 됩니다.
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1  = new PopupMenu("색상변경");
	PopupMenu* pm2  = new PopupMenu("해상도변경");

	root->add(pm1);
//	root->add(pm2);
	pm1->add(pm2);
	root->add(new MenuItem("자동설정", 11));

	pm1->add(new MenuItem("Red",   21));
	pm1->add(new MenuItem("Green", 22));
	pm1->add(new MenuItem("Blue",  23));
	pm1->add(new MenuItem("White", 24)); // 새로운 메뉴 추가

	pm2->add(new MenuItem("HD",  31));
	pm2->add(new MenuItem("FHD", 32));
	pm2->add(new MenuItem("UHD", 33));

	// 이제 시작하려면 ?
	root->command();
}

// 객체지향 프로그래밍 관점에서 프로그램이란 ?

// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고
// 3. 객체간의 메세지를 주고 받는 과정이다(서로의 멤버함수를 호출한다는 것)
// 4. 프로그램의 기본 단위는 "함수" 가 아닌 "클래스" 이다.

// 장점 : 확장성이 뛰어나고 유지보수가 쉽다.

// 단점 : 어렵다.
//		  메모리 사용량이 증가할수도 있고, C보다 느릴수도 있다.
//	      (필요없는 멤버데이타들.. 가상함수 등.. )
