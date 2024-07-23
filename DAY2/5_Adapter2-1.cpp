// ������ ������ ��� �����ϸ� 
// => ��� ����, �پ��� ������ ������ ���̱� �����մϴ�.
// => �̶��� �׻� "�ǵ�" �� �����ϼ���

// decorator vs object adapter �� �ڵ尡 ������ ���Դϴ�.

// ZipDecorator
class ZipDecorator : public Stream
{
	Stream* stream;	
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s) override
	{
		auto data = "[ " + s + " ����� ]";

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

// Decorator : �������̽��� ������ �ʴµ�, ����� �߰��Ȱ�
// Adapter   : �������̽�(�Լ��̸�)�� ����Ȱ�, �ϴ� ���� ����