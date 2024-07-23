// 디자인 패턴을 계속 공부하면 
// => 어느 순간, 다양한 패턴이 동일해 보이기 시작합니다.
// => 이때는 항상 "의도" 를 생각하세요

// decorator vs object adapter 는 코드가 동일해 보입니다.

// ZipDecorator
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

// ObjectAdapter
class ObjectAdapter : public Shape
{
	TextView* tview; 

public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() override
	{
		tview->show();
	}
};


FileStream fs("a.txt");
ZipDecorator zd(&fs);

fs.write("hello");
zd.write("hello");


TextView tv("hello");
ObjectAdapter oa(&tv);

tv.show();
oa.draw();

// Decorator : 인터페이스는 변하지 않는데, 기능이 추가된것
// Adapter   : 인터페이스(함수이름)가 변경된것, 하는 일은 동일