#include <iostream>

void print(int x) {std::cout << "int : " << x << std::endl;}
// void print(char x) {std::cout << "char : " << x << std::endl;}
void print(double x) {std::cout << "double : " << x << std::endl;}
// 오버로드란, 위와 같이 함수 이름이 아닌, 인자값에 따라 실행하는 내용이 달라지는 개념임. -> 이름이 같아도 인자가 다르면 다른 함수라고 취급함.
// 만약 여기서 char x 를 인자로 받는 print 함수가 사라진다면 ? -> 99로 출력하게 됨.

// 여기서 알 수 있는 내용은, 오버로딩의 3단계가 있다는걸 알 수 있음.
// 1, 자신과 타입이 정확히 일치하는 함수를 찾음.
// 2, 정확히 일치하는 타입이 없는 경우 형변환을 통해 일치하는 함수를 찾아봄. ex) char,unsigned char, short -> int 로
// 3, 변환을 해도 일치하는 것이 없다면 조금 더 포괄적인 형변환으 통해 일치하는 함수를 찾음(숫자를 다른 숫자 타입으로). ex) float -> int
// 4, 유저 정의된 타입 변환으로 일치하는 것을 찾음. 

// 만약 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나, 같은 단계에서 두개이상 일치하면 '모호하다' 판단해서 오류를 발생하게 됨.

void overload_ex(){
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);
}

class Date{
    int year_;
    int month_;
    int day_;

    public:
        void set_date(int year, int month, int date);
        void add_day(int inc);
        void add_month(int inc);
        void add_year(int inc);

        int get_current_month_total_days(int year, int month);

        void show_date();

        Date(){
            year_ = 1111;
            month_ = 1;
            day_ = 1;
        }

        Date(int year, int month, int day){ // 얘가 생성자임 클래스 이름 (인자) {} 형식으로 정의함
            year_ = year;
            month_ = month;
            day_ = day;
        }
};

void Date::set_date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::get_current_month_total_days(int year, int month){
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month != 2){
        return month_day[month - 1];
    } else if (year % 4 == 0 && year % 100 != 0){
        return 29;
    } else{
        return 28;
    }
}

void Date::add_day(int inc){
    while (1){
        int current_month_total_days = get_current_month_total_days(year_, month_);

        if (day_ + inc <= current_month_total_days){
            day_ += inc;
            return;
        } else {
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            add_month(1);
        }
    }
}

void Date::add_month(int inc){
    add_year((inc + month_ - 1) /12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::add_year(int inc) {year_ += inc;}

void Date::show_date(){
    std::cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_ << " 일 입니다." << std::endl;
}

void date_ex(){
    Date day(2024, 4 ,1);

    day.set_date(2024, 4, 1);
    day.show_date();

    day.add_day(30);
    day.show_date();

    day.add_day(2000);
    day.show_date();

    day.set_date(2012,1,31);
    day.add_day(29);
    day.show_date();

    day.set_date(2012, 8, 4);
    day.add_day(2500);
    day.show_date();
}

int main(){
    Date day(2024, 4 ,1);
    day.show_date(); // 초기화를 하지 않고 실행시키면 가비지값이 들어가게 됨. -> 생성자를 통해 해결 가능 (python : __init__)

    Date day2 = Date();
    day2.show_date();
    

    return 0;
}