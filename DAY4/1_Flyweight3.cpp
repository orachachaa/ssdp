// 2 번 복사해오세요.
// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};

// Image : 기름을 다운로드해서 그리는 기능
// Factory : Image의 객체의 생성과 공유를 제공

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)
	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		// 자료구조(map) 에서 "url" 키값이 있는지 검색
		auto it = image_map.find(url);

		if (it != image_map.end())
		{
			img = it->second;   // map 은 pair 보관
			// first 는 키값, second 는 value
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
	ImageFactory& factory = ImageFactory::get_instance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



