#include <stdio.h>

void temp_func1(){
    int a = 2147483647;
    printf("a = %d \n", a);
    a++;
    printf("a = %d \n", a);
}

void temp_func2(){
    unsigned int b = 4294967295;
    printf("b = %u \n", b);
    b++;
    printf("b = %u \n", b);
}

int main(void) {
    temp_func1();
    temp_func2();

    return 0;
}

// 어떠한 수의 보수를 얻으려면 반전시킨 후, 1을 더하면 됨.
// -> 6이라면 0110 -> 1001 -> 1010

// 하지만 위 예제처럼 1을 더했지만, 자료형의 최대 범위보다 큰 수를 대입하므로써 발생하는 문제를 오버플로우 라고 함.
// 음수를 표현하는 signed int 에선 -2147483648로, 음수를 표현하지 않는 unsigned int 에선 0으로 바뀜.