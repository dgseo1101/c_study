#include <stdio.h>

// void 함수는 return 값이 없는 함수.
void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
} // ^^ 이런 예제는 사실 return값이 필요가 없으니 이렇게 하는게 가독성이 좋음.

int void_var(){
    void *a; // 함수도 선언 가능
    double b = 123.4;

    a = &b;

    printf("%lf", *(double *)a);

    return 0;
}

int read_char(void *p, int byte);

int main(){
    int arr[1] = {0x12345678};
    printf("%x \n", arr[0]);

    read_char(arr, 4);
}

int read_char(void *p, int byte){
    do {
        printf("%x \n", *(char *)p);
        byte--;

        p = (char *)p + 1;
    } while (p && byte);

    return 0;
}