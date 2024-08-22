#include <stdio.h>
#include <stdlib.h>

struct BOOK{
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};

typedef struct BOOK BOOK;

int register_book(BOOK *book_list, int *nth){
    printf("책 이름 : ");
    scanf("%s", book_list[*nth].book_name);
    printf("책 저자 : ");
    scanf("%s", book_list[*nth].auth_name);
    printf("출판사 : ");
    scanf("%s", book_list[*nth].publ_name);
    book_list[*nth].borrowed = 0;
    (*nth)++;
    return 0;
}

char compare(char *str1, char *str2){
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

int search_book(BOOK *book_list, int total_num_book){
    int user_input;
    int i;
    char user_search[30];
    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 책 제목\n");
    printf("2. 지은이\n");
    printf("3. 출판사\n");
    scanf("%d", &user_input);
    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);

    if (user_input == 1){
        for (i = 0; i < total_num_book; i++){
            if (compare(book_list[i].book_name, user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
            }
        }
    } else if (user_input == 2){
        for (i = 0; i < total_num_book; i++){
            if (compare(book_list[i].auth_name, user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
            }
        }
    } else if (user_input == 3){
        for (i = 0; i < total_num_book; i++){
            if (compare(book_list[i].publ_name, user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
            }
        }
    }
    return 0;
}

int borrow_book(BOOK *book_list){
    int book_num;
    printf("빌릴 책 번호를 입력해주세요 : ");
    scanf("%d", &book_num);

    if (book_list[book_num].borrowed == 1){
        printf("이미 대출된 책입니다 \n");
    } else {
        printf("대출 성공 \n");
        book_list[book_num].borrowed == 1;
    }

    return 0;
}

int return_book(BOOK *book_list){
    int book_num;
    printf("반납할 책 번호를 입력해주세요 : ");
    scanf("%d", &book_num);

    if (book_list[book_num].borrowed == 0){
        printf("이미 반납된 책입니다 \n");
    } else {
        printf("반납 성공 \n");
        book_list[book_num].borrowed == 0;
    }

    return 0;
}

int save_book(BOOK *book_list, int num_total_book){
    FILE *fp = fopen("book.txt","w");

    if (fp == NULL){
        printf("error ! \n");
        return 0;
    }

    fprintf(fp, "책이름 / 저자 / 출판사 / 대출여부 \n"); // fp 에 stdout을 넣으면 터미널에 출력됨. -> 지정한 스트림에 출력되게 하는 함수
    for (int i = 0; i < num_total_book; i++){
        fprintf(fp, "%s / %s / %s / ", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);

        if (book_list[i].borrowed == 0){
            fprintf(fp, "NO \n");
        } else {
            fprintf(fp, "YES \n");
        }
    }

    fclose(fp);
}

int retrieve_book_info(BOOK **book_list, int *num_total_book){
    FILE *fp = fopen("book.txt", "r");

    int total_book;
    int i;
    char str[10];

    if (fp == NULL){
        printf("file open error \n");
        return 0;
    }

    fscanf(fp, "%d", &total_book);
    (*num_total_book) = total_book;

    free(*book_list);

    (*book_list) = (BOOK *)malloc(sizeof(BOOK) * total_book);

    if (*book_list == NULL){
        printf("error \n");
        return -1;
    }

    for (i = 0; i < total_book; i++){
        fscanf(fp, "%s", (*book_list)[i].book_name);
        fscanf(fp, "%s", (*book_list)[i].auth_name);
        fscanf(fp, "%s", (*book_list)[i].publ_name);
        fscanf(fp, "%s", str);

        if (compare(str, "YES")){
            (*book_list)[i].borrowed = 1;
        } else {
            (*book_list)[i].borrowed = 0;
        }
    }

    fclose(fp);
    return 0;
}

int print_book(BOOK *book_list, int num_total_book){
    for (int i = 0; i<num_total_book; i++){
        printf("%s / %s / %s / ", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
        if (book_list[i].borrowed == 0){
            printf("NO \n");
        } else {
            printf("YES \n");
        }
    }
}

int main(){
    int user_choice;
    int num_total_book = 0;
    BOOK *book_list;
    printf("도서관의 최대 보관 책 수를 설정해주세요 : ");
    scanf("%d", &user_choice);
    book_list = (BOOK *)malloc(user_choice * sizeof(BOOK));

    while (1){
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
        printf("6. 책 내용을 파일로 저장 \n");
        printf("7. 파일에서 책 내용 불러오기 \n");
        printf("8. 책 목록 출력 \n");
        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);

        if (user_choice == 1){
            register_book(book_list, &num_total_book);
        } else if (user_choice == 2){
            search_book(book_list, num_total_book);
        } else if (user_choice == 3){
            borrow_book(book_list);
        } else if (user_choice == 4){
            return_book(book_list);
        } else if (user_choice == 5){
            break;
        } else if (user_choice == 6){
            save_book(book_list, num_total_book);
        } else if (user_choice == 7){
            retrieve_book_info(&book_list, &num_total_book);
        } else if (user_choice == 8){
            print_book(book_list, num_total_book);
        }
    }

    free(book_list);

    return 0;
}

