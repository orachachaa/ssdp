#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	// 공장에서는 Image 객체를 만들수 있어야 한다.
	friend class ImageFactory;

};

// SRP : 단일 책임의 원칙(Single Responsibility Principle)
// => 하나의 클래스는 하나의 책임만

// Image        : 그림을 다운해서 그리는 기능만 제공
// ImageFactory : Image 객체의 생성과 공유를 제공

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it != image_map.end())
		{
			img = it->second;
		}
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return img;
	}
};


int main()
{
	ImageFactory factory;


	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



