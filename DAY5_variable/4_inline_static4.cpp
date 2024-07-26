class AAA;

AAA* p;

class Cursor
{
public:
	inline static int data;

	//inline static Cursor c;
	static Cursor c;
};
inline Cursor Cursor::c;

// Sample.cpp
// #include "Sample.h"

int main()
{
}