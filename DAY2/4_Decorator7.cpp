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
		printf("%s ¾²±â\n", s.c_str());
	}
};

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {} 
	void write(const std::string& s) override
	{
		auto data = "[" + s + " ¾ÐÃàµÊ ]";
		stream->write(data);
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}
	void write(const std::string& s) override
	{
		auto data = "[" + s + " ¾ÏÈ£È­µÊ ]";
		stream->write(data);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello");

	ZipDecorator zd(&ed);
	zd.write("hello");
}
