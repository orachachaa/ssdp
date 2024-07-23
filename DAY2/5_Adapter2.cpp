#include <iostream>
#include <string>
#include <vector>


class TextView
{
	std::string data;

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

// 어답터 패턴의 종류
// class 어답터  : 클래스의 인터페이스를 변경
// object 어답터 : 객체의 인터페이스 변경


class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

class ObjectAdapter : public Shape
{
	TextView* tview; // 핵심 : 이미 생성된 객체를 가리키기 위한 포인터

public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() override
	{
		? ;
	}
};



int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스
						  // tv       : 객체

//	v.push_back( &tv ); // ? 이미 생성된 객체 tv 를 v에 넣을수 있을까요 ?
						// error. Shape 에서 파생되지 않았고
						//		  draw 도 없다
}







