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


	inline static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url)
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
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



