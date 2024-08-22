#include <stdio.h>

void dp(){
    int a;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    a = 3;

    // printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
    // printf("&a : %p // pa : %p // *ppa : %p \n", &a, pa, *ppa);
    // printf("&pa : %p // ppa : %p \n", &pa, ppa);

    printf("a : %d // &a : %p \n", a, &a);
    printf("*pa : %d // pa : %p // &pa : %p \n", *pa, pa, &pa);
    printf("**ppa : %d // *ppa : %p // ppa : %p // &ppa : %p \n", **ppa, *ppa, ppa, &ppa);

    // pa는 a의 주소값을 가르키고, ppa는 pa의 주소값을 가르킴.
    // 그리하여 위와 같이 출력됨.
}

void p1(){
    int arr[3] = {1,2,3};
    int (*parr)[3] = &arr;

    printf("arr[1] : %d : %p\n", arr[1], arr);
    printf("parr[1] : %d : %p\n", (*parr)[1], parr);
}

void p2(){
    int arr[2][3] = {{1,2,3},{4,5,6}};

    printf("arr[0][0] : %d // %p \n", arr[0][0], &arr[0][0]);
    printf("arr[1][0] : %d // %p \n", arr[1][0], &arr[1][0]);
}

void p3(){
    int *arr[3];
    int a = 1, b = 2, c = 3;

    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    printf("a : %d (%p) // *arr[0] : %d (%p)\n", a, &a,*arr[0], arr[0]);
    printf("b : %d (%p) // *arr[1] : %d (%p)\n", b, &b,*arr[1], arr[1]);
    printf("c : %d (%p) // *arr[2] : %d (%p)\n", c, &c,*arr[2], arr[2]);

}

int main(){
    // dp();
    // p1();
    // p2();
    p3();
    return 0;
}