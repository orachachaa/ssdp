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
	TextView* tview;
public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() override
	{
		tview->show();
	}
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("hello");

	// v.push_back(&tv);
	v.push_back(new ObjectAdapter(&tv));
	v[0]->draw();
}







