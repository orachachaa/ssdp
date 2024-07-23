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

int main()
{
	// 파일에 쓸 때 암호화 해서 쓰는 기능이 필요합니다.

	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello");

	ZipDecorator zd(&ed);
	zd.write("hello");
}
