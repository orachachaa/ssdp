// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>


class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장할 필요가 있는 데이타는 별도의 구조체로 설계
	struct Memento
	{
		int penWidth;
		int penColor;

		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};

	std::map<int, Memento*> m;
	int key = 0;

public:
	int Save()
	{
		Memento* memento = new Memento(penWidth, penColor);

		m[++key] = memento;

		return key;
	}
	void Restore(int token)
	{
		penColor = m[token]->penColor;
		penWidth = m[token]->penWidth;
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	// 1번예제에서 "방법 #2" 사용
	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // Memento 패턴
						  // => 객체가 자신의 상태를 저장 했다가 복구할수 있게한다.
						  // => 캡슐화를 위해 하지 않고, 객체의 저장/복구 제공.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore( token );
}


// Undo 를 구현하는 방법
// command : 동작의 취소를 사용한 Undo
// memento : 객체의 상태 저장을 사용한 Undo - 메모리 사용량 증가할수 있음






