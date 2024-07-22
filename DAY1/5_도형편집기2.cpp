#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v) // A.  s의 타입은 Shape*
				s->draw();	 // B. error
		}
	}
}
// 위 코드는 왜 컴파일 에러일까요 ?
// => A 부분에서  s 의 타입인 Shape* 인데.
// => Shape 에는 "draw" 가 없기 때문에 "B" 에서 컴파일 에러
// 
// 해결책은 뭘까요 ?
// => 다음소스에서.. 

