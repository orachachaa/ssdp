#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

// 전통적인 디자인 패턴에서는 command5.cpp 처럼 "factory method" 로 하지만
// C++ 이라면 "template" 이 더 좋을수도 있다

template<typename T>
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new T); }
	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};



class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override
	{
		for (auto s : v) s->draw();
	}

	bool can_undo() override { return true; }

	void undo() override { system("cls"); }
};


// 여러개 명령을 보관했다가 한번에 실행하는 명령
class MacroCommand
{
	std::vector<ICommand*> v;
public:
	void add(ICommand* cmd) { v.push_back(cmd); }

	void execute()
	{
		for (auto cmd : v)
			cmd->execute();
	}
};


int main()
{
	std::vector<Shape*> v;

	MacroCommand* mc1 = new MacroCommand;
	mc1->add(new AddCommand<Rect>(v));
	mc1->add(new AddCommand<Circle>(v));
	mc1->add(new DrawCommand(v));
	mc1->execute();





	std::stack<ICommand*> cmd_stack;

	ICommand* command = nullptr;


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			command = new AddCommand<Rect>(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 2)
		{
			command = new AddCommand<Circle>(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 0)
		{
			if (cmd_stack.empty() == false)
			{
				command = cmd_stack.top();
				cmd_stack.pop();

				if (command->can_undo())
					command->undo();

				delete command;
			}
		}
	}
}







