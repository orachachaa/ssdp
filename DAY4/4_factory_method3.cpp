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

// 각 OS 별로 컨트롤의 클래스 이름만 관리하는 구조체
struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};

struct Windows
{
	using Button = WinButton;
	using Edit = WinEdit;

	// 여기에 모든 컨트롤의 클래스 이름에 대한 별명포함
};



template< typename Style >
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename Style::Button;
		IEdit* edit = new typename  Style::Edit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};

int main(int argc, char** argv)
{
	// 템플릿 인자로 각 컨트롤의 이름을 가진 구조체 전달.
	Dialog<OSX> dlg;
}



