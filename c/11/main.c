#include <stdio.h>

char copy_str(char *dest, const char *src);
char str_len(char *str);
int compare(char *str1, char *str2);

int main(){
    char str[] = "hello";
    char *pstr = "goodbye";

    compare(str, pstr);

    // str[1] = "a";
    // pstr[1] = "a"; // 이렇게 하면 여기서 에러 발생 리터럴 이라고 하는데, 이는 간단하게 읽기 전용 이라 생각하면 되며, 보통 쌍따옴표로 묶여있음.
    //                 // 근데 왜 str[1] = "a"는 되느냐 ? -> str = {"h", "e", "l","l","o"}로 되어있기에 리터럴 이라고 보기 힘듬.
    //                 // VS 2017이상에서 리터럴을 char*가 가르킬 수 없음. 반드시 const char* 가 가르켜야함

    return 0;
}

void temp_func(){
    int num;
    char c, str[20];

    printf("숫자 입력 : ");
    scanf("%d", &num);

    printf("문자 입력 : ");
    scanf("%c", &c); // 이건 위 숫자 입력 부분의 버퍼에서 \n이 남아 바로 종료하게 됨. 

    scanf("%s", str); // 얘는 공백문자가 아닌 실질적인 문자만 담기에 잘 받아옴
    printf("%s", str); 
}

void temp_func2(){
    char str1[10], str2[10];

    printf("문자열 : ");
    scanf("%s", str1); // %s만 쓴다고 다 해결되진 않음.
    printf("입력한 문자열 : %s \n", str1); // input에 "asd asd" 와 같이 공백문자가 나오면 입력을 중지함.

    printf("문자열 : "); 
    scanf("%s", str2);
    printf("입력한 문자열 : %s \n", str2);
}

void temp_func3(){
    int num;
    char c, ch;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    ch = getchar(); // 이걸로 버퍼를 비워줄 수 있음. -> 정상적으로 사용 가능

    printf("tc : %c", ch);
    printf("문자를 입력하세요 : ");
    scanf("%c", &c);
}

void temp_func4(){
    char str[] = "sentence";
    char *pstr = "sentence"; // 신기하게 이게 가능함. -> "sentence" 라는 문자열이 저장된 주소값을 말함.

    printf("%s : %p\n", str, &str); 
    printf("%s : %p\n", pstr, &str);
}

char copy_str(char *dest, const char *src){
    while (*src){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}

char str_len(char *str){
    int i = 0;
    while (str[i]){
        i++;
    }

    return i;
}

int compare(char *str1, char *str2){
    while (*str1){
        if (*str1 != *str2){
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1;

    return 0;
}