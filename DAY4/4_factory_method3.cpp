// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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
// Style �ɼǰ� ������� �׻� Windows ����� Dialog

// �� OS ���� ��Ʈ���� Ŭ���� �̸��� �����ϴ� ����ü
struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};

struct Windows
{
	using Button = WinButton;
	using Edit = WinEdit;

	// ���⿡ ��� ��Ʈ���� Ŭ���� �̸��� ���� ��������
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
	// ���ø� ���ڷ� �� ��Ʈ���� �̸��� ���� ����ü ����.
	Dialog<OSX> dlg;
}



