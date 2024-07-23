#include <string>
#include <iostream>

//template<typename T,
//	typename Traits = std::char_traits<T>,
//	typename Alloc = std::allocator<T>>
//class basic_string
//{
//	T* ptr;
//	Alloc ax;
//public:
//	bool operator==(const std::basic_string& other)
//	{
//		return Traits::compare(ptr, other.ptr);
//	}
//};
//
//int main()
//{
//	std::string s1 = "abcd";
//	std::string s2 = "ABCD";
//
//	std::cout << (s1 == s2) << std::endl; // 0 ? 1
//}
//
//using string = std::basic_string<char>;
//using wstring = std::basic_string<wchar_t>;


//struct MyTraits
//{
//};
struct MyTraits : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char)ch);
    }

    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return to_upper(c1) < to_upper(c2);
    }

    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }

    static const char* find(const char* s, std::size_t n, char a)
    {
        const auto ua{ to_upper(a) };
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

using ci_string = std::basic_string<char, MyTraits>;

int main()
{
    ci_string s1 = "abcd";
    ci_string s2 = "ABCD";

    std::cout << (s1 == s2) << std::endl; // 0 ? 1
}