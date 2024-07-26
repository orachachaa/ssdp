// 6_Mediator - 중재자 패턴 
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	// 아래 가상함수는 자신의 체크 상태가 변경될때 마다 호출됩니다.
	virtual void ChangeState() {}
};


class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		if (GetCheck() == true)
			std::cout << "ebable button\n";
		else 
			std::cout << "disable button\n";
	}
};


int main()
{
	MyCheckBox c;
	c.SetCheck(true);
}



