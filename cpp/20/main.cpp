#include <iostream>
#include <string>
#include <cstring>

template <typename T>
void print(T arg){
    std::cout << arg << std::endl;
}

template <typename T, typename... Types> // ...으로 받는것을 파라미터 팩 이라고 부름.
void print(T arg, Types... args){ // 탬플릿 파라미터 팩과 함수 파라미터 팩은, ...이 앞이냐 뒤냐에 따른 차이가 있음.
    std::cout << arg << ", ";
    print(args...);
}

template <typename String>
std::string StrCat(const String& s){
    return std::string(s);
}

size_t GetStringSize(const char* s) { return strlen(s);}

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs){
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str){return;}

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs){
    concat_str->append(s);
    AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    size_t total_size = GetStringSize(s, strs...);

    std::string concat_str;
    concat_str.reserve(total_size);

    concat_str = s;
    AppendToString(&concat_str, strs...);
    
    return concat_str;
}

int sum_all() {return 0;}

template <typename... Ints>
int sum_all(int num, Ints... nums){
    return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums){
    return static_cast<double>(sum_all(nums...)) / sizeof...(nums); // sizeof... 을 할 경우, 전체 인자의 개수를 리턴하게됨.
}

template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums){
    return (start - ... - nums);
}

class A{
    public:
        void do_something(int x) const{
            std::cout << "Do something with" << x << std::endl;
        }
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums){
    (t.do_something(nums), ...);
}

int main(){
    print(1, 3.1, "abc");
    print(1,2,3,4,5,6,7);

    std::cout << StrCat(std::string("this"), " ", "is"," ", std::string("a"), " ", std::string("sentence")) << std::endl;

    std::cout << average(1,4,2,3,10) << std::endl;

    std::cout << sum_all(1,4,2,3,10) << std::endl;

    std::cout << diff_from(100, 1,4,2,3,10) << std::endl;
 
    A a;
    do_many_things(a ,1,3,2,4);
    return 0; 
}