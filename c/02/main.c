#include <stdio.h>

int main(){
    int a;
    a = 10;
    printf("a = %d \n", a);

    float b = 3.141592f; // f를 명시해주는 이유는, 그냥 float b = 3.141592 라고 적으면 double 형으로 인식하여 문제가 생길 수 있기 때문.
    double c = 3.141592;
    printf("b = %f \n" , b);
    printf("c = %f \n", c);
    printf("b = %.2f \n" , b); // %.2f는 소수점 자리

    return 0;

}

// int 는 -2147483648 ~ 2147483647 까지 표현이 가능함.
// 그래서 해당 범위를 초과하는 값을 입력하면 이상한 값이 출력되게됨.

// char / 1바이트 / -128 ~ 127 (unsigned char 면 0~255)
// short / 최소 2바이트 / -32,768 ~ 32,767 (unsigned short 0~65,535)
// int /최소 2바이트, 보통 4바이트 / 4바이트의 경우 -2147483648 ~ 2147483647 (unsigned int 0~4,294,967,295)
// long / 32비트에선 4바이트, 64비트에선 8바이트
// long long / 최소 8바이트
// float / 4바이트
// double / 8바이트