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
		std::cout << get_title() << " �޴� ���õ�\n";

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
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";

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
	PopupMenu* pm1 = new PopupMenu("���󺯰�");
	PopupMenu* pm2 = new PopupMenu("�ػ󵵺���");

	root->add(pm1);
	root->add(pm2);
	root->add(new MenuItem("�ڵ�����", 11));

	// submenu �� ������ ���ô�.
	auto m = root->submenu(0);


	// �Ʒ� �ڵ忡 ���ؼ� ������ ���ô�.
//	root->submenu(0)->add(new MenuItem("Red", 11));
				// error. add �� PopupMenu �� �ִµ�
				// "root->submenu(0)" �� ����� "BaseMenu*"
				// ĳ������ �ʿ� �ϴ�.

	static_cast<PopupMenu*>(root->submenu(0))->add(new MenuItem("Red", 11));

	root->command();
}


