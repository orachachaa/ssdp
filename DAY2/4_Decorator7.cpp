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
		printf("%s 쓰기\n", s.c_str());
	}
};
// FileStream, NetworkStream, PipeStream 등에 기능을 추가하는
// Decorator 들..
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s) override 
	{
		auto data = "[ " + s + " 압축됨 ]";

		stream->write(data);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");		

	EncrpytDecorator ed(&fs);
	ed.write("hello");			

	ZipDecorator  zd(&ed);
	zd.write("hello");			
}
