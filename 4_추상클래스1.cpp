// 1_추상클래스1.cpp - 10page

class Shape
{
public:
	virtual void draw() = 0; 
							 
};
class Rect : public Shape
{
	void draw() override {}
};
int main()
{
	Shape  s; // error
	Shape* p; // ok
	Rect  r;
}
