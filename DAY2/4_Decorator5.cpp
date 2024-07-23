// visual studio 에서 fopen, scanf 등을 사용할때 아래 매크로 필요
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 다양한 Stream 의 함수이름을 약속하기 위한 인터페이스

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// 이외에도 read, flush, is_open 등의 다양한 함수를 여기서 약속
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

	/*
	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");


	PipeStream ps("mynamedpipe");
	ps.write("hello");
	*/
}
