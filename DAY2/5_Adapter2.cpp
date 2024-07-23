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

// ����� ������ ����
// class �����  : Ŭ������ �������̽��� ����
// object ����� : ��ü�� �������̽� ����


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
	TextView* tview; // �ٽ� : �̹� ������ ��ü�� ����Ű�� ���� ������

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

	TextView tv("hello"); // TextView : Ŭ����
						  // tv       : ��ü

//	v.push_back( &tv ); // ? �̹� ������ ��ü tv �� v�� ������ ������� ?
						// error. Shape ���� �Ļ����� �ʾҰ�
						//		  draw �� ����
}







