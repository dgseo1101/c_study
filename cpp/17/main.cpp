#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void file_open_ex(){
    std::ifstream in("test.txt");
    std::string s;

    
    if (in.is_open()){
        in >> s;
        std::cout << "입력받은 문자열 : " << s << std::endl; 
    } else {
        std::cout << "don't find file" << std::endl;
    }
}

void file_open_ex2(){
    std::ifstream in("test.txt", std::ios::binary);
    std::string s;

    int x;
    if (in.is_open()){
        in.read((char*)(&x), 4);
        std::cout << "입력받은 문자열 : " <<std::hex << x << std::endl; 
    } else {
        std::cout << "don't find file" << std::endl;
    }
}

void read_all(){
    std::ifstream in("test.txt");
    std::string s;

    
    if (in.is_open()){
        in >> s;
        // 위치 지정자를 파일 끝으로 옮김. (= in C - fseek)
        in.seekg(0, std::ios::end);

        // 그리고 파일 크기를 받아오기 위해 그 위치를 읽고
        int size = in.tellg();

        // 그 크기의 문자열 할당
        s.resize(size);

        // 위치 지정자를 다시 맨 앞으로 옮긴다음
        in.seekg(0, std::ios::beg);

        // 파일 전체 내용을 읽어 문자열에 저장함
        in.read(&s[0], size);
        std::cout << s << std::endl;
    } else {
        std::cout << "file open error" << std::endl;
    }
}

void get_line_ex(){
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()){
        std::cout << "file read error" << std::endl;
    }

    while(in){
        in.getline(buf, 100); // 파일에 개행문자 (\n) 이 나올때 까지 지정한 크기 -1 만큼 읽게됨. (마지막 문자로 종료문자인 널을 넣어줘야하기 때문)
                              // in.getline(buf, 100, '.'); 하면, .이 나올때까지 입력을 받게됨.
                              // 추가로, 개행문자가 나오기 전 버퍼의 크기가 다 차면, failbit을 켜서 정상적으로 데이터를 받을 수 없음.
        std::cout << buf << std::endl;
    }
}

void get_line_ex2(){
    std::ifstream in("test.txt");

    if (!in.is_open()){
        std::cout << "file read error" << std::endl;
    }

    std::string s;
    while(in){
        getline(in, s);
        std::cout << s << std::endl;
    }
}

void file_out_ex(){
    std::ofstream out("test.txt");

    std::string s;
    if (out.is_open()){
        out << "test";
    }
}

void file_out_add_ex(){
    std::ofstream out("test.txt", std::ios::app); // app은 붙여 쓰게 됨. 
                                                  // 외에도 ate (자동으로 파일 끝에서 부터 읽기와 쓰기를 실시함, 즉 파일을 열때 위치 지정자가 파일 끝을 가리키고 있음)
                                                  // trunc (파일 스트림을 열면, 기존에 있던 내용들이 모두 지워짐.)
                                                  // in, out (파일에 입출력을 결정함.)

    std::string s;
    if (out.is_open()){
        out << "add";
    }
}

void app_ate_dif(){
    std::ofstream out("test.txt", std::ios::app); 
    std::ofstream out2("test2.txt", std::ios::ate);

    out.seekp(3, std::ios::beg); // 얘를 움직이게 되면, 현재 파일은 빈파일이라 생각되어 위치지정자가 움직이지 않고 출력됨.
    out2.seekp(3, std::ios::beg); // 하지만 얘는, 기존에 있던 내용이 삭제되고 써짐 -> 기존 파일 내용을 보존하지 X

    out << "추가";
    out2 << "추가";
}

class Human{
    std::string name;
    int age;

    public: 
        Human(const std::string&name, int age) : name(name), age(age) {} 
        std::string get_info(){
            return "name :: " + name + " / age :: " + std::to_string(age);
        }

        friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h){
    o << h.get_info();
    return o;
}

void ofstream_operator_overloading(){
    std::ofstream out("test.txt");

    Human h("서동근" , 23);
    out << h << std::endl;
}

void sstream_ex(){
    std::istringstream ss("123"); // 문자열 숫자를
    int x;
    ss >> x; // 이렇게 쉽게 변환할 수 있음
    
    std::cout << "입력 받은 데이터 :: " << x << std::endl;
}

double to_number(std::string s){
    std::istringstream ss(s);
    double x;

    ss >> x;
    return x;
}

int main(){
    std::cout << "변환:: 1+ 2 = " << to_number("1") + to_number("2") << std::endl;

    return 0;
}