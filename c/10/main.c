#include <stdio.h>

int print_hello(){
    printf("Hello world \n");
    return 0;

    // for (int i = 0; i<3; i++){
    //     print_hello();
    // }
}

int ret() {return 1000;}

int add(int a){
    a += 10;
    return a;
    // int a = ret();
    // printf("%d\n", a);
    // a = add(a);
    // printf("%d \n", a);

}

int slave(int pre_money, int add_money){
    pre_money += add_money;
    return pre_money;
} 

int sum_n(int n){
    int sum = 0;
    for (int i = 0; i<n+1; i++){
        sum += i;
    }
    return sum;

    // int sum = sum_n(3);
    // printf("%d \n", sum);
}

int po_add(int *p){
    *p = 3;
    return 0;

    // int i = 0;
    // po_add(&i);
    // printf("%d \n", i);
}

int swap(int *i, int *j){
    int temp = *i;

    *i = *j;
    *j = temp;

    return 0;

    // int i = 5, j = 3;
    // swap(&i, &j);
    // printf("%d / %d \n", i, j);

}

int add_array(int *parr){
    for (int i = 0; i<3; i++){
        parr[i]++;
    }
    return 0;

    // int arr[3];
    // for (int i = 0; i<3; i++){
    //     scanf("%d", &arr[i]);
    // }

    // add_array(arr);
    // printf("%d / %d / %d", arr[0], arr[1], arr[2]);
}

int max_number(int *parr){
    int max = parr[0];

    for (int i = 0; i < 10; i ++){
        if (parr[i] >= max){
            max = parr[i];
        } 
    }

    return max;
    // int arr[10], max;
    // for (int i = 0; i<10; i ++){
    //     arr[i] = i;
    // }

    // max = max_number(arr);
    // printf("%d", max);
}

int isdisit(char c){
    if (48 <= c && c <= 57){ // 아스키 코드 값이 48 ~ 57임
        return 1;
    }else{
        return 0;
    }
    // char input;
    // scanf("%c", &input);

    // if (isdisit(input)){
    //     printf("%c 는 숫자 \n", input);
    // } else{
    //     printf("%c 는 숫자 아님 \n", input);
    // }
}

int pswap(int **ppa, int **ppb){
    int *temp = *ppa;

    printf("ppa : %p \n", ppa);
    printf("ppb : %p \n", ppb);

    *ppa = *ppb;
    *ppb = temp;

    return 0;

    // int a,b;
    // int *pa, *pb;

    // pa = &a;
    // pb = &b;

    // printf("pa : %p // pb : %p \n", pa, pb);
    // printf("&pa : %p // &pb : %p \n", &pa, &pb);

    // pswap(&pa, &pb);

    // printf("pa : %p // pb : %p\n", pa, pb);
    // printf("&pa : %p // &pb : %p\n", &pa, &pb);
}

int add1_element(int (*arr)[2], int row){ // (*arr)[2] = arr[][2]
    for (int i = 0; i < row; i++){
        for (int j = 0; j < 2; j++){
            arr[i][j]++;
        }
    }

    return 0;

    // int arr[3][2];

    // for (int i = 0; i < 3; i++){
    //     for (int j = 0; j < 2; j++){
    //         arr[i][j] = i + j;
    //     }
    // }

    // add1_element(arr, 3);

    // for (int i = 0; i < 3; i++){
    //     for (int j = 0; j < 2; j++){
    //         printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
    //     }
    // }

}

int max(int a, int b){
    if (a>b){
        return a;
    } else {
        return b;
    }

    // int a,b;
    // int (*pmax)(int, int); // 함수 포인터 정의 pmax는 return 값이 int형이고, input으로 int 두개를 받는다. (함수의 return 자료형) (* 포인터 이름)(parameter) 
    // pmax = max;  //함수의 시작 주소값을 알려면 그냥 함수 이름을 넣어줌, pmax = &max는 틀림                                      // 인자가 없다면 int (*a)()

    // a = 5;
    // b = 6;

    // printf("max(a, b) : %d \n", max(a,b));
    // printf("pmax(a, b) : %d \n", pmax(a,b));
}

int increase(int (*arr)[3], int row){
    for (int i = 0; i<row; i++){
        for (int j = 0; j<3; j++){
            arr[i][j] += 1;
        }
    }
}

int main(){
    int arr[3][3];
    int (*pfunc)(int (*)[3], int);
    pfunc = increase;

    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            arr[i][j] = i + (j * 2);
        }
    }    

    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            printf("%d", arr[i][j]);
        }
    }  

    pfunc(arr, 3);
    printf("\n\n");

    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            printf("%d", arr[i][j]);
        }
    }    

    return 0;
}