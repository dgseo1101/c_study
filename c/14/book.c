#include <stdio.h>
#include "book.h"
#include "str.h"

int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book){
    printf("추가할 책 제목 : ");
    scanf("%s", book_name[*num_total_book]);

    printf("추가할 책 저자 : ");
    scanf("%s", auth_name[*num_total_book]);

    printf("추가할 책 출판사 : ");
    scanf("%s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0;
    printf("추가 완료 \n");

    (*num_total_book)++;

    return 0;
}

int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int num_total_book){
    int user_input;
    int i;
    char user_search[30];

    printf("어느것으로 검색 ? \n");
    printf("1, 제목 \n 2, 지은이 \n 3, 출판사 \n");
    printf("항목 선택 : ");
    scanf("%d", &user_input);

    printf("검색할 단어 : ");
    scanf("%s", user_search);

    if (user_input == 1){
        for (i = 0; i<num_total_book; i++){
            if (compare(book_name[i], user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    } else if (user_input == 2){
        for (i = 0; i<num_total_book; i++){
            if (compare(auth_name[i], user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,book_name[i], auth_name[i], publ_name[i]);
            }
        }
    } else if (user_input == 3){
        for (i = 0; i<num_total_book; i++){
            if (compare(publ_name[i], user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }
    
    
    return 0;
}

int borrow_book(int *borrowed){
    int book_num;

    printf("빌릴 책 번호 : ");
    scanf("%d", &book_num);
    
    if (borrowed[book_num] == 1){
        printf("이미 대출된 책 입니다. \n");
    } else {
        borrowed[book_num] = 1;
        printf("대출 성공 \n");
    }

    return 0;
}

int return_book(int *borrowed){
    int book_num;

    printf("반납할 책 번호 : ");
    scanf("%d", &book_num);
    
    if (borrowed[book_num] == 0){
        printf("이미 반납된 책 입니다. \n");
    } else {
        borrowed[book_num] == 0;
        printf("반납 성공 \n");
    }

    return 0;
}