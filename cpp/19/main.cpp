#include <iostream>
#include <string>
#include <array>

template <typename T>

class Vector{
    T* data;
    int capacity;
    int length;

    public:
        typedef T value_type;

        Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

        void push_back(T s){
            if (capacity <= length){
                T* temp = new T[capacity * 2];
                for (int i = 0; i < length; i ++){
                    temp[i] = data[i];
                }
            delete[] data;
            data = temp;
            capacity *=  2;
            }

            data[length] = s;
            length ++;
        }

        T operator[](int i) {return data[i];}

        void remove(int x){
            for (int i = x + 1; i < length; i++){
                data[i - 1] = data[i];
            }
            length--;
        }

        int size() {return length;}

        void swap(int i, int j){
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        ~Vector(){
            if (data){
                delete[] data;
            }
        }

};

template <>
class Vector<bool>{
    unsigned int* data;
    int capacity;
    int length;

    public:
        typedef bool value_type;

        Vector(int n = 1):
            data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0){
                for (int i = 0; i < capacity; i++){
                    data[i] = 0;
                }
            }

        void push_back(bool s) {
            if (capacity * 32 <= length) {
            unsigned int* temp = new unsigned int[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                temp[i] = data[i];
            }
            for (int i = capacity; i < 2 * capacity; i++) {
                temp[i] = 0;
            }

            delete[] data;
            data = temp;
            capacity *= 2;
            }

            if (s) {
            data[length / 32] |= (1 << (length % 32));
            }

            length++;
        }

        bool operator[](int i) {return (data[i/32] & (1 << (i % 32))) != 0;}

        void remove(int x){
            for (int i = x + 1; i < length; i++){
                int prev = i - 1;
                int curr = i;

                if (data[curr / 32] & (1 << (curr % 32))){
                    data[prev / 32] |= (1 << (prev % 32));
                }

                else{
                    unsigned int all_ones_except_prev = 0xFFFFFFFF;
                    all_ones_except_prev ^= (1 << (prev % 32));
                    data[prev / 32] &= all_ones_except_prev;
                }
            }
            length --;
        }

        int size() {return length;}
        ~Vector() {
            if (data) {
            delete[] data;
            }
        }
};

template <typename T>
T max(T& a, T& b){
    return a> b ? a : b;
}

template <typename Cont>
void bubble_sort(Cont& cont) {
    for (int i = 0; i < cont.size(); i++) {
        for (int j = i + 1; j < cont.size(); j++) {
            if (cont[i] > cont[j]) {
                cont.swap(i, j);
            }
        }
    }
}

template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
    for (int i = 0; i < cont.size(); i++) {
        for (int j = i + 1; j < cont.size(); j++) {
            if (!comp(cont[i], cont[j])){
                cont.swap(i, j);
            }
        }
    }
}

struct Comp1 {
    bool operator()(int a, int b) { return a > b; }
};

struct Comp2 {
    bool operator()(int a, int b) { return a < b; }
};

template <typename T, int num = 5>
T add_num(T t){
    return t + num;
}

template <typename T>
void print_arr(const T& arr){
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 

template <typename T>
struct Compare{
    bool operator()(const T& a, const T& b) const {return a < b;}
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b){
    Comp comp;
    if (comp(a, b)){
        return a;
    }
    return b;
}

void template_ex_1(){
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "int vector" << std::endl;
    std::cout << "first par : " << int_vec[0] << std::endl;
    std::cout << "second par : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "string vector" << std::endl;
    std::cout << "first par : " << str_vec[0] << std::endl;
    std::cout << "second par : " << str_vec[1] << std::endl;

    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);

    std::cout << "-------- bool vector ---------" << std::endl;
    for (int i = 0; i < bool_vec.size(); i++) {
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;
}

void template_ex_2(){
    int a = 1, b = 2;
    std::cout << "Max (" << a << "," << b << ") ? :" << max(a, b) << std::endl;

    std::string s = "hello", t = "world";
    std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
}

void template_ex_3(){
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);

    std::cout << "정렬 이전" << std::endl;
    for (int i = 0; i < int_vec.size(); i++){
        std::cout << int_vec[i] << " ";
    }

    Comp1 comp1;
    bubble_sort(int_vec, comp1);


    std::cout << std::endl << "내림차순 정렬 이후" << std::endl;
    for (int i = 0; i < int_vec.size(); i++){
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;

    Comp2 comp2;
    bubble_sort(int_vec, comp2);

    std::cout << std::endl << "오름차순 정렬 이후" << std::endl;
    for (int i = 0; i < int_vec.size(); i++){
        std::cout << int_vec[i] << " ";
    }
    std::cout<<std::endl;
}


int main() {
    int x = 3;
    std::cout << "x : " << add_num(x) << std::endl;

    std::array<int, 5> arr = {1,2,3,4,5};
    std::array<int, 7> arr2 = {1,2,3,4,5,6,7};
    std::array<int, 3> arr3 = {1,2,3};

    print_arr(arr);
    print_arr(arr2);
    print_arr(arr3);

    int a = 3, b = 5;

    std::cout << "Min " << a << "," << b << " :: " << Min(a, b) << std::endl;

    std::string s1 = "abc", s2 = "def";
    std::cout << "Min " << s1 << ", " << s2 << " :: " << Min(s1, s2) << std::endl;
    return 0;  
}