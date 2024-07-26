class Cursor
{
public:
	inline static int data = 0; // ok

	inline static Cursor c; // error
};

int main()
{

}