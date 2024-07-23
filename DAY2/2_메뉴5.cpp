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
		std::cout << get_title() << "�޴� ���õ�\n";

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
			std::cout << sz + 1 << ". ����\n";
			std::cout << "�޴��� �����ϼ��� >> ";

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
	MenuItem m1("��ġ ���", 11);
	MenuItem m2("�Ұ��� ���", 12);
	MenuItem m3("��� ���", 13);

	MenuItem m5("���", 51);

	PopupMenu kimbab("����");
	kimbab.add(&m1);
	kimbab.add(&m2);
	kimbab.add(&m3);

	PopupMenu pm("������ ���ɸ޴�");
	pm.add(&kimbab);
	pm.add(&m5);

	pm.command();
}




