// thiscall
class Point
{
	int x, y;
public:
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
};

int main()
{
	Point p1, p2;

	p1.set(10, 20); // 원리를 정확히 알아 봅시다.
}