#include <iostream>
#include <cstring>

class A{
    private:
        void private_func() {}
        int private_num;

        friend class B;

        friend void func();
};

class B{
    public:
        void b(){
            A a;

            // 친구로 지정했기에 접근 가능.
            // 근데 이건 짝사랑 같은 느낌이라, B->A 로 접근은 가능하지만, A->B 로는 안됨 (B에서 friend 등록을 하면 가능)
            a.private_func();
            a.private_num = 2;
        }
};

void func(){
    A a;

    a.private_func();
    a.private_num = 2;
}

class Complex{
    private:
        double real, img;

        double get_number(const char* str, int from, int to) const;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) {real = c.real, img = c.img;}
        Complex(const char* str);

        Complex operator+(const Complex& c) const;
        Complex& operator=(const Complex& c);

        void println() {std::cout << "(" << real << " , " << img << ")" << std::endl;}

        friend Complex operator+(const Complex& a, const Complex& b);

        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex operator+(const Complex& a, const Complex& b){
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}

Complex::Complex(const char* str){
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for (int i = 0; i != end; i++){
        if (str[i] == 'i'){
            pos_i =i;
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

double Complex::get_number(const char* str, int from, int to) const{
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool int_part = true;
    for (int i = from; i <= to; i++){
        if (isdigit(str[i]) && int_part){
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.'){
            int_part = false;
        } else if (isdigit(str[i]) && !int_part){
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else break;
    }

    if (minus) num *= -1.0;

    return num;
}

Complex Complex::operator+(const Complex& c) const{
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
    os << "(" << c.real << " , " << c.img << ")";
    return os;
}

void add_ex(){
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    a = a + a; // 난 왜 되는거지
    a.println();

    Complex b(1,2);
    b = a + b;
    b.println();

    std::cout << "a 값은 : " << a << "이다." << std::endl;
}

class Int{

    int data;

    public:
        Int(int data) : data(data) {}
        Int(const Int& i) : data(i.data) {}

        operator int() {return data;}
};

void int_ex(){
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;

}

class Test{
    int x;

    public:
        Test(int x) : x(x) {}
        Test(const Test& t) : x(t.x) {}

        Test& operator++(){ // ++x
            x++;
            std::cout << "전위 증감 연산자" << std::endl;
            return *this;
        }

        Test operator++(int){ // x++ 
            Test temp(*this);
            x++;
            std::cout << "후위 증감 연산자" << std::endl;
            return temp;
        }

        int get_x() const{return x;}
};
// 후위 증감 연산의 경우, 추가적으로 복사 생성자를 호출하기에 전위 증감 연산보다 더 느림.


void func(const Test& t){
    std::cout << "x : " << t.get_x() << std::endl;
}


int main(){
    Test t(3);
    
    func(++t);
    func(t++);

    std::cout << "x : " << t.get_x() << std::endl;

    return 0;
}

// 정리
// 두 개의 동등한 객체 사이에서 이항연산자는 멤버 함수가 아닌 외부 함수로 오버로딩 하는게 바람직함. ex) Complex의 operator+(const Complex &, const Complex&) const 처럼 선언하고 friend로 묶기.
// 두 객체 사이의 이항 연산자 이지만, 한 객체만 값이 바뀐다던지 등의 동등하지 않은 이항 연산자는 멤버 함수로 오버로딩하는게 좋음. ex) operator+= 는 이항연산자 이지만, operator+=(const Complex&) 가 낫다.
// 단항 연산자는 멤버 함수로 오버로딩 하는게 좋음 ex) operator++의 경우 멤버함수로 오버로딩함.
// 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야함. (+=, -= 같은 얘들.) (+,-,*,/ 얘네는 무조건 외부 함수로 선언하기)