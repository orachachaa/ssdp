// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// Style 옵션과 상관없이 항상 Windows 모양의 Dialog

class DialogBase
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}

	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};

class WinDialog : public DialogBase
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit() override { return new WinEdit; }
};
class OSXDialog : public DialogBase
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit() override { return new OSXEdit; }
};
int main(int argc, char** argv)
{

}




