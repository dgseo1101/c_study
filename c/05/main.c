#include <stdio.h>

void pyramid(int n){
    int i,j;
    for (i=0; i<n; i++){
        for (j = 1; j<n-i; j++){
            printf(" ");
        }

        for (j = 0; j<=(i*2); j++){
            printf("*");
        }

        printf("\n");
    }
} 

void reverse_pyramid(int n){
    int i,j = 0;
    for (i = n; i>0; i--){
        for (j = 0; j<n-i; j++){
            printf(" ");
        }

        for (j = 1; j<=(i*2-1); j++){
            printf("*");
        }
        printf("\n");
    }
}

void q3(){
    int i=0, sum=0;
    for (i; i < 1001; i++){
        if (i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    printf("sum : %d", sum);
}

void q4(){
    int f1 = 0, f2 =1;
    int f3, i, sum;

    for (i=2; i<=1000000; i++){
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
        if (f3 % 2 == 0){
            sum += f3;
        }
    }

    printf("sum : %d", f3);

}

void q5(int n){
    int i, mul=1;
    for (i=1; i<n+1; i++){
        mul *= i;
    }
    printf("mul : %d", mul);
}

void q6(){
    int a,b,c, num=0;

    for (a = 0; a<2001; a++){
        for (b = 0; b<2001; b++){
            for (c = 0; c<2001; c++){
                if ((a+b+c == 2000) && (a > b && b > c)){
                    num+=1;
                }
            }
        }
    }
    printf("num : %d", num);
}

void q7(int n){
    int i = 2;
    while (n != 1){
        if (n % i == 0){
            n /= i;
            printf("%d", i);
            i = 2;
        } else{
            i += 1;
        }
    }

}

int main(void){
    // pyramid(3);
    // reverse_pyramid(3);
    // q3();
    // q4();
    // q5(5);
    // q6();
    q7(12);
    return 0;
}