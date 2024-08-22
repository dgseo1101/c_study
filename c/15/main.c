#include <stdio.h>
#include "human.h"
#include <string.h>

#define VAR 10 // #define, 매크로 이름, 값 형식 
#define A

int struct_include(){
    struct Human lee = create_human("lee", 40, MALE);

    print_human(&lee);

    return 0;
}

int open_lib(){
    char str1[20] = {"hi"};
    char str2[20] = {"hello"};

    strcpy(str1, str2); // 여태껏 구현했던 함수가 라이브러리에도 있음
    printf("str1 : %s \n", str1);

    if (!strcmp(str1, str2)){ // 얘도 마찬가지
        printf("%s and %s is equal \n", str1, str2);
    } else{
        printf("%s and %s is not equal \n", str1, str2);
    }

    return 0;
}

int define_func(){
    char arr[VAR] = {"Hi"};

    printf("%s \n", arr);
    return 0;
}

int main(){
    #ifdef A
    printf("AAA \n");
    #endif
    #ifdef B
    printf("BBB \n");
    #endif
    return 0;

    // ifdef 는 endif와 같이 사용하며, 매크로가 정의 되었다면 (ex #define A) 실행시키고 그렇지 않다면 실행시키지 않음.
}