#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s) 
	{
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	//NetworkStream ns("100.100.100.100", 3000);
	//ns.write("hello");

	//PipeStream ps("mynamepipe");
	//ps.write("hello");
}
