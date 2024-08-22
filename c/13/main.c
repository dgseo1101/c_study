#include <stdio.h>

int* function(){
    int a = 2;
    // return &a;
}

int* s_function(){
    static int b =3;
    return &b;
}

int global = 3;

int main(){
    int i;
    char *str = "aaa";
    char arr[3] = "bbb";

    printf("str : %p \n", str); //리터럴인 얘의 주소값이 가장 낮음
    printf("global : %p \n", &global); //전역변수로 데이터 영역에 위치함.
    printf("i : %p \n", &i); // 지역변수이기에 stack에 위치함. (스택은 추가할수록 메모리 주소가 작아짐)
    printf("arr : %p \n", arr); // 위 괄호 안에 내용때문에 i보다 값이 작음 (왜 난 더 크지)
}

int static_func(){
    // int* pa = function();
    // printf("%d \n", *pa); // 변수는 정의된 지역을 벗어나면 소멸됨.

    int* pb = s_function();
    printf("%d \n", *pb); // 이렇게 static으로 정적 변수로 만들어준다면 소멸되지 않음. (얘는 프로그램이 종료되며 소멸함)
    return 0;
}