#include <stdio.h>
#define square(x) x *x // #define 함수이름(인자) 치환할 것 
#define radtodeg(x) ((x) * 57.295)
#define printvarname(var) printf(#var "\n"); // 전처리기 문에서만 사용되는 것 중 #은, 어떠한 인자 앞에 붙이게 되면 문자열로 바꾸어 버림.
#define addname(x,y) x##y // 얘는 합쳐주는 역할임. int addname(a,b) = int ab 로

__inline int inline_square(int a) {return a * a; }

__inline int inline_max(int a, int b){
    if (a > b)
        return a;
      else 
        return b;
    
}

void print_square(){
    printf("square(3) : %d \n", square(3));
    printf("square(3+1) : %d \n", square(3+1)); // 3+1*3+1 로 인식함.
    printf("square((3+1)) : %d \n", square((3+1))); // 이렇게 하거나 위 함수 정의를 square(x) (x) * (x) 로 바꾸면 됨.
}

void print_radian(){
    printf("5 rad 는 : %f", radtodeg(5));
}

void print_var(){
    int a;
    printvarname(a);
}

void print_addname(){
    int addname(a,b);
    ab = 3;

    printf("%d \n", ab);
}

// void print_inline(){
//     printf("%d", inline_square(3));
// }

int main(){
    // printf("%d", inline_max(3,2));

    return 0;
}