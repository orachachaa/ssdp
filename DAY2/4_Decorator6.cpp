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
	// 파일에 쓸때 암호화 해서 쓰는 기능이 필요합니다.
	// 최선의 설계를 생각해 봅시다.

	// 방법 #1. FileStream 을 처음 만들때 부터 encrpywrite 같은 기능을 넣는다
	// => 암호화 기능이 필요 없다면...
	// => 암호화 외에도 생각지 못한 많은 기능이 미래에 요구될수 있다..

	// 방법 #2. 상속을 사용하면 어떨까 ?
	// FileStream 에서 파생된 "EncryptFileStrean"
	// => NetworkStream, PipeStream 도 파생 클래스 필요!!
	// => 암호화, 압축 등의 기능일 필요하고, 중첩해서 사용하려면
	//    상속이 복잡해 진다.

	// 방법 #3. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("hello");			// 파일에 직접 쓰기

	EncrpytDecorator ed(&fs);
	ed.write("hello");			// 1. "hello" 을 암호화 한후 <= 추가된 기능
								// 2. fs.write(암호화된 데이타)

	ZipDecorator  zd(&ed);
	zd.write("hello");			// 1. "hello" 를 압축하고
								// 2. ed.write(압축된 데이타)

}
