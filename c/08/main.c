#include <stdio.h>

void p1(){
    int a = 2;
    printf("%p", &a);
}

void p2(){
    int a=2;
    int *p = &a; // 포인터는 *로 정의되며, 주소값을 계산할 데이터는 &로 넣음
    printf("%p", p);
}

void p3(){
    int *p;
    int a;

    p = &a; // 포인터에 a의 주소값을 집어넣고,
    a = 2; // a에는 2를 넣음.

    printf("a : %d \n", a);
    printf("p : %p \n", p); // 이렇게 하면 주소값을 출력하고
    printf("p : %d \n", *p); // 이렇게하면 해당 주소값의 값을 출력함
}

void p4(){
    int a,b;
    int *p;

    p = &a;
    *p = 10;
    p = &b;
    *p = 4;

    printf("%d \n", a);
    printf("%d \n", b);
}

void p5(){
    int chul, sue;
    int *young;

    young = &chul;
    *young = 3;
    young = &sue;
    *young = 4;

    printf("%d \n", chul);
    printf("%d \n", sue);
}

void p6(){
    int *p;
    int a = 2;

    printf("%p \n", p); // <- 이 포인터는 nil 값임 (null pointer 라는 뜻)
    printf("%d : %p\n", a, &a); // <- 변수 a에는 2라는 값이 담겨져 있고, 해당 변수의 메모리 주소는 뒤에 출력되는 값임.

    p = &a;  // 이렇게 하면 pointer는 a의 메모리 영역을 가르키게 됨.
    printf("%d : %p\n", a, &a);
    printf("%d : %p \n", *p, p);
    
}

void p7(){
    int a,b;
    const int* const pa = &a; // 이렇ㄱ ㅔ하면 고정 가능
}

void p8(){
    int a;
    int* pa;
    pa = &a;

    printf("pa : %p\n", pa);
    printf("pa + 1 : %p \n", pa + 1);
}

void p9(){
    int arr[5] = {1,2,3,4,5};
    int *p;
    p = arr; // 이거나 &arr[0]이나 똑같음

    printf("%p : %p", p + 1, &arr[1]);
}

int main() {
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8();
    p9();
    return 0;
}