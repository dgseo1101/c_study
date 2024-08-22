#include <iostream>
#include <string.h>

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
        int capacity () const;
        void reserve(int size);
        char at(int i) const;

        void print() const;
        void println() const;

        int find(int find_from, my_string& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;

        int compare(const my_string& str) const;

        my_string& insert(int loc, const my_string& str);
        my_string& insert(int loc, const char* str);
        my_string& insert(int loc, char c);

        my_string& assign(const my_string& str);
        my_string& assign(const char* str);
        my_string& erase(int loc, int num);

};

my_string::my_string(char c){
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
my_string::my_string(const char* str){
    string_length = strlen(str);
    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
my_string::my_string(const my_string& str){
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

my_string::~my_string() {delete[] string_content;}

int my_string::len() const {return string_length;}

void my_string::print() const {
    for (int i = 0; i != string_length; i++){
        std::cout << string_content[i];
    }
}

void my_string::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

my_string& my_string::assign(const my_string& str){
    if (str.string_length > memory_capacity){
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++){
        string_content[i] = str.string_content[i];
    }

    string_length = str.string_length;

    return *this;
}

my_string& my_string::assign(const char* str){
    int str_length = strlen(str);
    if (str_length > memory_capacity){
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }

    for (int i = 0; i != str_length; i++){
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}

int my_string::capacity() const {return memory_capacity;}

void my_string::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
        string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}

char my_string::at(int i) const{
    if (i >= string_length || i < 0){
        return 0;
    } else {
        return string_content[i];
    }
}

my_string& my_string::insert(int loc, const char* str){
    my_string temp(str);
    return insert(loc, temp);
}

my_string& my_string::insert(int loc, char c){
    my_string temp(c);
    return insert(loc, temp);
}

my_string& my_string::insert(int loc, const my_string& str){
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char [memory_capacity];

        int i;
        for (i = 0; i < loc; i++){
            string_content[i] = prev_string_content[i];
        }

        for (int j = 0; j != str.string_length; j++){
            string_content[i + j] = str.string_content[j];
        }

        for (; i < string_length; i++){
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;

        return *this;
    }

    for (int i = string_length - 1; i >= loc; i--){
        string_content[i + str.string_length] = string_content[i];
    }

    for (int i = 0; i < str.string_length; i++){
        string_content[i + loc] = str.string_content[i];
    }

    string_length = string_length + str.string_length;
    return *this;
}

my_string& my_string::erase(int loc, int num){
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    for (int i = loc + num; i < string_length; i++){
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}

int my_string::find(int find_from, my_string& str) const{
    if (str.string_length == 0) return -1;
    
    int i, j;
    for (i = find_from; i <= string_length - str.string_length; i++){
        for (j = 0; j < str.string_length; j++){
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1;
}

int my_string::find(int find_from, const char* str) const{
    my_string temp(str);
    return find(find_from, temp);
}

int my_string::find(int find_from, char c) const{
    my_string temp(c);
    return find(find_from, temp);
}

int my_string::compare(const my_string& str) const{
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



void insert_ex(){
    my_string str1("very long string");
    my_string str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.len() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String Length : " << str1.len() << std::endl;
    str1.println();
}

void find_ex(){
    my_string str1("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str1.find(0, "very") << std::endl;
    std::cout << "Location of second <very> in the string : " << str1.find(str1.find(0, "very") + 1, "very") << std::endl;
}

int main(){
    my_string str1("abcdef");
    my_string str2("abcde");

    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;

    return 0;
}