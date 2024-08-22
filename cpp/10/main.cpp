#include <iostream>

class my_string{
    char* string_content;
    int string_length;

    int memory_capacity;

    public:
        my_string(int capacity);
        my_string(const char* str);
        my_string(const my_string& str);
        ~my_string();

        int len() const;
};

my_string::my_string(int capacity){
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

my_string::my_string(const char* str){
    string_length = 0;
    while(str[string_length++]){
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

my_string::my_string(const my_string& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++){
        string_content[i] = str.string_content[i];
    }
}

my_string::~my_string() {delete[] string_content;}
int my_string::len() const {return string_length; }

void temp_string_func(my_string s){
    // pass
}

class A{
    mutable int data_;

    public:
        A(int data) : data_(data){}
        void do_something(int x) const{
            data_ = x;
        }

        void print_data() const {std::cout << "data: " << data_ << std::endl;}
};

int main() {
    A a(10);
    a.do_something(3);
    a.print_data();
}