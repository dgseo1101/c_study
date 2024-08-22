#include <stdio.h>

void casting(){
    int a;
    float b;

    b = 2.4;
    a = (int)b;
    printf("%d", a);
}

void casting_2(){
    int a,b;
    float c,d;

    a = 10;
    b = 3;

    c = a/b;
    d = (float) a/b;

    printf("%f %f", c,d);
}

void q1(){
    float i = 12.3456;

    i = (int)(i * 100) % 100;

    printf("%d \n", (int)i);
}

int main(void){
    // casting();
    // casting_2();
    q1();
    return 0;
}