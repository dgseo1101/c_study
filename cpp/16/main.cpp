#include <iostream>
#include <string>

using namespace std;

void io_ex(){
    int t;
    while (std::cin >> t){
        std::cout << "input : " << t << std::endl; 
        if (t == 0) break;
    }
}

void except_ex(){
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;

        if (std::cin.fail()){
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        if (t == 1) break;
    }
}

void fail_ex(){
    int t;
    while (true) {
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield); // 얘의 버전은 2개가 있음, 하나는 인자를 한개만 받는거고 다른 하나는 이것처럼 두개를 받는 것
                                                                    // 하나는 그냥 인자로 준 형식 플래그를 적용하지만, 2개는 basefield의 내용을 초기화 하고, 첫번째 인자를 적용하는 것.
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;

        if (std::cin.fail()){
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();
        }

        if (t == 1) break;
    }
}

int main(){
    std::string s;
    std::cin >> s;

    char peek = std::cin.rdbuf()->snextc();
    if (std::cin.fail()) std::cout << "Failed";
    std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
    std::cin >> s;
    std::cout << "다시 읽으면 : " << s << std::endl;
    
}