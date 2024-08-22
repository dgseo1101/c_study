#include <iostream>
#include <string.h>

// 연산자 오버로딩
// (리턴 타입) operator (연산자) (파라미터) 형식임.

class my_string{
    char* string_content;
    int string_length;

    int memory_capacity;

    public:
        my_string(char c);
        my_string(const char* str);
        my_string(const my_string& str);

        ~my_string();

        int len() const;
        int capacity() const;
        void reserve(int size);

        void print() const;
        void println() const;
        
        char at(int i) const;
        int compare(my_string& str);
        bool operator==(my_string& str);

        char& operator[](const int index);
};

my_string::my_string(char c){
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

my_string::my_string(const char* str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

my_string::my_string(const my_string& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

my_string::~my_string() {delete[] string_content;}
int my_string::len() const {return string_length;}

void my_string::print() const {for (int i = 0; i != string_length; i++) std::cout << string_content[i];}
void my_string::println() const {for (int i = 0; i != string_length; i++) std::cout <<string_content[i];
    std::cout << std::endl;
} 

int my_string::capacity() const {return memory_capacity;}
void my_string::reserve(int size){
    if (size > memory_capacity){
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}

char my_string::at(int i) const {
    if (i >= string_length || i < 0)
        return 0;
    else
        return string_content[i];
}

int my_string::compare(my_string& str){
    for (int i = 0; i < std::min(string_length, str.string_length); i++){
        if (string_content[i] > str.string_content[i])
            return 1;

        else if (string_content[i] < str.string_content[i])
            return -1;
    }

    if (string_length == str.string_length) return 0;

    else if (string_length > str.string_length)
        return 1;
    
    return -1;
}

bool my_string::operator==(my_string& str){
    return !compare(str);
}

char& my_string::operator[](const int index) {return string_content[index]; }

void temp_ex(){
    my_string str1("a word");
    my_string str2("sentence");
    my_string str3("sentence");

    if (str1 == str2)
        std::cout << "str1 == str2" << std::endl;
    else 
        std::cout << "str1 != str2" << std::endl;

    if (str2 == str3)
        std::cout << "str2 == str3" << std::endl;
    else
        std::cout << "str2 != str3" << std::endl;
}

class Complex{
    private:
        double real, img;

        double get_number(const char *str, int from, int to) const;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex&c) {real = c.real, img = c.img;}
        Complex(const char* str);

        Complex operator+(const Complex& c) const;
        Complex operator+(const char* str) const;

        Complex operator-(const Complex& c) const;
        Complex operator-(const char* str) const;
        Complex operator*(const Complex& c) const;
        Complex operator*(const char* str) const;
        Complex operator/(const Complex& c) const;
        Complex operator/(const char* str) const;
        Complex operator=(const Complex& c);


        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        void println() {std::cout << "(" << real << " , " << img << ")" << std::endl;}
};

Complex::Complex(const char* str){
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for (int i = 0; i != end; i++){
        if (str[i] == 'i'){
            pos_i = i;
            break;
        }
    }

    if (pos_i == -1){
        real = get_number(str, begin, end - 1);
        return;
    }

    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

Complex Complex::operator+(const Complex& c) const{
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator+(const char* str) const {
    Complex temp(str);
    return (*this) + temp;
}

Complex Complex::operator-(const char* str) const{
    Complex temp(str);
    return (*this) - temp;
}

Complex Complex::operator-(const Complex& c) const{
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) const{
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator*(const char* str) const{
    Complex temp(str);
    return (*this) * temp;
}

Complex Complex::operator/(const Complex& c) const{
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex Complex::operator/(const char* str) const{
    Complex temp(str);
    return (*this) / temp;
}

Complex& Complex::operator+=(const Complex& c){
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c){
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c){
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c){
    (*this) = (*this) / c;
    return *this;
}

Complex Complex::operator=(const Complex& c){
    real = c.real;
    img = c.img;
    return *this;
}

double Complex::get_number(const char *str, int from, int to) const{
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if(str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part){
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else
            break;
    }

    if (minus) num *= -1.0;

    return num;
}



void temp_ex2(){
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    Complex c(0.0, 0.0);

    c = a * b + a / b + a + b;
    c.println();

    // Some_class a = b; -> 얘는 복사 생성자가 호출됨. 
    // ------ 
    // Some_class a; -> 얘는 그냥 생성자가 호출된 다음
    // a = b;        -> 대입연산자 싫애

}

void add_ex(){
    Complex a(1.0, 2.0);
   Complex b(3.0, -2.0);
   a += b;
   a.println();
   b.println(); 
}

void add_ex2(){
    Complex a(0,0);
    a = a + "-1.1 + i3.923";
    a.println();

    a = a - "1.2 - i1.823";
    a.println();

    a = a * "2.3+i22";
    a.println();

    a = a / "-12+i55";
    a.println();
}

int main(){
    my_string str("abcdef");
    str[3] = 'c';

    str.println();

    return 0;
}