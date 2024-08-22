#include <stdio.h>
#include "book.h"

int main(){
    int user_choice;
    int num_total_book = 0;

    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    int borrowed[100];

    while (1){
        printf("메뉴 선택 \n");
        printf("1, 책 추가 \n");
        printf("2, 책 검색 \n");
        printf("3, 책 빌리기 \n");
        printf("4, 책 반납 \n");
        printf("5, 프로그램 종료 \n");
        printf("메뉴 : ");
        scanf("%d", &user_choice);

        if (user_choice == 1){
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        } else if (user_choice == 2){
            search_book(book_name, auth_name, publ_name, num_total_book);
        } else if (user_choice == 3){
            borrow_book(borrowed);
        } else if (user_choice == 4){
            return_book(borrowed);
        } else if (user_choice == 5){
            break;
        }
    }

    return 0;
}