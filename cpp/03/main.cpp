#include <iostream>

int _change_val(int *p){
    *p = 3;

    return 0;
}
void change_val_ex(){
    int number = 5;

    std::cout << number << std::endl;
    _change_val(&number);
    std::cout << number << std::endl;
}

void refer_ex(){
    int a = 3;
    int& another_a = a; // 참조자 (포인터 타입이라면 int*& 와 같이 사용 가능)

    another_a = 5; // another_a 는 a의 참조자임. -> 또다른 이름을 컴파일러에게 알려주는 개념이며, another_a 에서 작업할 시 그 내용이 a에도 들어감.
    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;    
}

void refer_ex_2(){
    int a = 10;
    int &another_a = a;

    std::cout << a << std::endl;

    int b = 3;
    another_a = b;

    std::cout << a << std::endl;
}

void different_refer_pointer(){
    int a = 10;
    int *p = &a;

    std::cout << p << std::endl; // p -> a

    int b = 3;
    p = &b;

    std::cout << p << std::endl; // p -> b
}

int change_val(int &p){ // 원래 int &p 는 선언이 안되지만, 파라미터로 들어가는건 사실 int &p = number; 와 같은 의미라 괜찮음
    p = 3;
    return 0;
}

int change_val_mem(){
    int number = 5;
    
    std::cout << number << std::endl;
    change_val(number);
    std::cout << number << std::endl;

    return 0;
}

void refer_ex_3(){
    int x;
    int& y = x;
    int& z = y;

    x = 1;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    
    y = 2;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    z = 3;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

void refer_ex_4(){
    const int &ref = 4;
    int a = ref;

    std::cout << a << std::endl;
}

void refer_array(){
    // int a, b;
    // int& arr[2] = {a,b}; // 이건 안됨 (언어 차원에서 막아둠.)
    
    int arr[3] = {1,2,3}; // 이렇게 바꿔야함. array를 선언하고.
    int (&ref)[3] = arr; // 참조자가 그 array를 참조할 수 있도록

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
}

int& function(){
    int a = 2;
    return a;
}

void dangling(){
    int b = function(); // function 함수는 a의 참조자를 리턴하게 되는데, a가 사라지게 되면서 에러를 발생함.
    b = 3;              // 이런걸 댕글링 레퍼런스라고 함.

}

int& function_2(int& a){
    a = 5;
    return a;
}

void func_2_ex(){
    int b = 2;          // 이렇게 하면 참조자를 받아올 수 있음.
    int c = function_2(b);  // 이렇게 한다면 참조하는 타입의 크기와 상관 없이 딱 한번 주소값 복사로 전달을 끝내 효율적임.

    std::cout << b << std::endl;
}

int function_3(){
    int a = 5;
    return a;
}

int main() {
    const int& c = function_3();

    std::cout << "c : " << c << std::endl;
    return 0;
}