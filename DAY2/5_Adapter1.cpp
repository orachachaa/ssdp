#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// => 문자열을 보관했다가 화면에 이쁘게 출력하는 클래스

class TextView
{
	std::string data;

	// font 이름, 크기, 기울기, 두께, 색상.. 
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};



//=================================================
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

// 도형편집기 시스템에 "문자열을 관리하는 클래스"를 추가하고 싶다.
// => 그런데, 예전부터 가지고 있던 "TextView" 를 사용하면 될거 같습니다
// => 여기서 사용할수 있을까요 ?
// => Shape 로 부터 상속받지 않았고, draw 함수가 아닌 show 이므로
//    직접 사용할수는 없다!!

// TextView 를 도형편집기 시스템에서 사용할수 있도록
// => 인터페이스(함수이름)을 변경해 봅시다.

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// "show" 라는 함수를 "draw" 라는 이름으로 변경해서
	// "인터페이스의 불일치" 를 해결하는 코드 입니다.
	void draw() override
	{
		TextView::show();
	}
};

// 어답터 패턴
// => 이미 존재 하는 클래스의 인터페이스(함수이름)을
//    Client 가 요구하는 형태로 변경해 주는 패턴
// => 인터페이스의 불일치를 해결하는 패턴

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw();
}







