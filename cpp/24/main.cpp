#include <cctype>
#include <iostream>
#include <string>

using namespace std::literals;

struct my_char_traits : public std::char_traits<char>{
    static int get_real_rank(char c){
        if (isdigit(c)){
            return c + 256;
        }
        return c;
    }

    static bool lt(char c1, char c2){
        return get_real_rank(c1), get_real_rank(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n){
        while (n-- != 0){
            if (get_real_rank(*s1) < get_real_rank(*s2)){
                return -1;
            }

            if (get_real_rank(*s1) > get_real_rank(*s2)){
                return 1;
            }

            ++s1;
            ++s2;
        }
        return 0;
    }
};

void* operator new(std::size_t count){
    std::cout << count << "bytes 할당 " << std::endl;
    return malloc(count);
}

void ex_1(){
    std::basic_string<char, my_char_traits> my_s1 = "1a";
    std::basic_string<char, my_char_traits> my_s2 = "a1";

    std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha << (my_s1 < my_s2) << std::endl;

    std::string s1 = "1a";
    std::string s2 = "a1";

    std::cout << "일반 문자열 :" << std::boolalpha << (s1 < s2) << std::endl;
}

void ex_2(){
    std::cout << "s1 생성 ---" << std::endl;
    std::string s1 = "this is a pretty long sentence !!!";
    std::cout << "s1 크기 : " << sizeof(s1) << std::endl;

    std::cout << "s2 생성 ---" << std::endl;
    std::string s2 = "short sentence";
    std::cout << "s2 크기 : " << sizeof(s2) << std::endl;
}

void ex_3(){
    const char* s = "hello";
    char s2[] = "hello";

    auto str = "hello"; // -> const char* 로 정의됨

    std::cout << typeid(s).name() << std::endl; // PKc = const char* 의 맹글링 된 이름임.
    std::cout << typeid(s2).name() << std::endl;
    std::cout << typeid(str).name() << std::endl;
}

void ex_4(){
    auto s1 = "hello"s;
    std::cout << "s1 길이 : " << s1.size() << std::endl; // -> string 형식임.
    std::string str = "hello"; //char[]
    std::wstring wstr = L"hello"; // wchar_t[]

    std::string str2 = R"(asd
    asdasd
    qweqw //
    \n\n
    #define asdasd
    )";

    std::cout << str2;

    std::string str3 = R"foo(

    )"; <== 무시됨
    )foo";

    std::cout << str3;
}

int main(){
    std::u32string u32_str = U"이건 UTF-32 문자열 입니다";
    std::cout << u32_str.size() << std::endl;

    std::string str = u8"이건 UTF-8 문자열 입니다";
    std::cout << str.size() << std::endl;

    return 0;
}