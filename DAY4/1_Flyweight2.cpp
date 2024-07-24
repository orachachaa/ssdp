// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// 속성이 동일한 객체는  공유 할수 있게 하자.


// Image : 인터넷에서 그림을 Download 해서 화면에 그리는 역활
class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	static Image* Create(const std::string& url)
	{
		Image* img = new Image(url);
	}
};

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



