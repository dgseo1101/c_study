#include <stdio.h>
#include <string.h>

int make_atxt(){
    FILE *fp;

    fp = fopen("a.txt", "w");

    if (fp == NULL){
        printf("Write Error ! \n");
        return 0;
    }

    fputs("Hello World ! \n", fp);

    fclose(fp);

    return 0;
}

void close_stdout(){
    fclose(stdout);
    printf("aa");
}

int read_file(){
    FILE *fp = fopen("a.txt", "r");

    char buf[20];

    if (fp == NULL){
        printf("read error \n");
        return 0;
    }

    fgets(buf, 20, fp);
    printf("입력받은 내용 : %s \n", buf);
    fclose(fp);
    return 0;
}

int get_file_size(){
    FILE *fp = fopen("a.txt", "r");
    int size = 0;

    while (fgetc(fp) != EOF){ //fgetc 는 한글자씩 읽어옴
        size ++;
    }

    printf("파일의 크기는 : %d bytes", size);
    fclose(fp);

    return 0;
}

void fseek_example(){
    FILE *fp = fopen("a.txt", "r");
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fseek(fp, 0, SEEK_SET); // 얘는 숫자에 해당하는 위치로 돌림.
    printf("%c \n", fgetc(fp)); 
    fclose(fp);
}

void fseek_overwrite(){
    FILE *fp = fopen("a.txt", "w");

    fputs("dgseo is an exllent C programmer", fp);
    fseek(fp, 0, SEEK_SET);
    fputs("is dgseo", fp); // 파일 앞에 끼워지는게 아닌, 덮어써짐. 
    fclose(fp);
}

void fgets_fseek_ex(){
    FILE *fp = fopen("a.txt", "r");
    char data[10];
    char c;

    if (fp == NULL){
        printf("file open error \n");
        return 0;
    }

    fgets(data, 5, fp);
    printf("입력받은 데이터 : %s \n", data);

    c = fgetc(fp);
    printf("입력받은 문자 : %c \n", c);

    fseek(fp, -1, SEEK_CUR);

    c = fgetc(fp);
    printf("%c \n", c);

    fclose(fp);
}

void fscan_ex(){
    FILE *fp = fopen("a.txt", "r");

    char data[100];

    if (fp == NULL){
        printf("file open error \n");
        return 0;
    }

    printf("입력받은 단어들 ---- \n");
    while (fscanf(fp, "%s", data) != EOF){ // fscanf 는, fp에서 문쟈열을 읽어오는데, \n \t 등 어느 하나가 나올 때 까지 입력을 받아 단어별로 읽어올때 요긴하게 쓰임.
        printf("%s \n", data);
    }

    fclose(fp);
}

int main(){
    FILE *fp = fopen("a.txt", "r+");

    char data[100];

    if (fp == NULL){
        printf("file open error \n");
        return 0;
    }

    while (fscanf(fp, "%s", data) != EOF) {
        if (strcmp(data, "dgseo") == 0) {
            fseek(fp, -(long)strlen("dgseo"), SEEK_CUR);
            fputs("byko", fp);  
        }
  }

    fclose(fp);

    return 0;
}