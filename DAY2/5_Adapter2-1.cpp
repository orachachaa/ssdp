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