#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// C 언어   : 메모리 구조를 이해하기 위해 "메모리 그림" 을 그리면서 학습
// 객체지향 : 디자인을 이해하기 위해 "클래스 Diagram" 을 그리면서 학습



class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }


	// 모든 메뉴는 선택될수 있다
	// => 모든 파생 클래스의 공통의 특징은 
	//    기반 클래스에도 있어야 한다.
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
	std::vector<BaseMenu*> v; // <== 이부분이 핵심!!!
							  // 기반 클래스 타입으로 보관하면 
							  // MenuItem, PopupMenu 모두 보관가능
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
	MenuItem m1("참치 김밥", 11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m3("돈까스 김밥", 13);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);
	kimbab.add(&m3);

	MenuItem m5("라면", 51);

	PopupMenu pm("오늘의 점심메뉴");

	pm.add(&kimbab); 
	pm.add(&m5);	 

	pm.command();
}




