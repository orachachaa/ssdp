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
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	// ���Ͽ� ���� ��ȣȭ �ؼ� ���� ����� �ʿ��մϴ�.
	// �ּ��� ���踦 ������ ���ô�.

	// ��� #1. FileStream �� ó�� ���鶧 ���� encrpywrite ���� ����� �ִ´�
	// => ��ȣȭ ����� �ʿ� ���ٸ�...
	// => ��ȣȭ �ܿ��� ������ ���� ���� ����� �̷��� �䱸�ɼ� �ִ�..

	// ��� #2. ����� ����ϸ� ��� ?
	// FileStream ���� �Ļ��� "EncryptFileStrean"
	// => NetworkStream, PipeStream �� �Ļ� Ŭ���� �ʿ�!!
	// => ��ȣȭ, ���� ���� ����� �ʿ��ϰ�, ��ø�ؼ� ����Ϸ���
	//    ����� ������ ����.

	// ��� #3. Decorator ������ ����ϸ� ��� ?

	FileStream fs("a.txt");
	fs.write("hello");			// ���Ͽ� ���� ����

	EncrpytDecorator ed(&fs);
	ed.write("hello");			// 1. "hello" �� ��ȣȭ ���� <= �߰��� ���
								// 2. fs.write(��ȣȭ�� ����Ÿ)

	ZipDecorator  zd(&ed);
	zd.write("hello");			// 1. "hello" �� �����ϰ�
								// 2. ed.write(����� ����Ÿ)

}
