#include <stdio.h>

struct Human {
    int age;
    int height;
    int weight;
    // struct Human Psi;

    // Psi.age = 99;
    // Psi.height = 185;
    // Psi.weight = 80;

    // printf("%d / %d / %d", Psi.age, Psi.height, Psi.weight);
};

struct Books{
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed;

    // copy_str(harry_potter.name, "harry potter");
    // copy_str(harry_potter.auth, "J.K Rolling");
    // copy_str(harry_potter.publ, "Scholastic");
    // harry_potter.borrowed = 0;

    // printf("책 이름 : %s \n", harry_potter.name);
    // printf("저자 이름 : %s \n", harry_potter.auth);
    // printf("출판사 이름 : %s \n", harry_potter.publ);

    // struct Books book_list[3];

    // int i;
    // for (i = 0; i < 2; i++){
    //     printf("%d 정보 입력 : ",i);
    //     scanf("%s %s %s", book_list[i].name, book_list[i].auth, book_list[i].publ);
    //     book_list[i].borrowed = 0;
    // }

    // for (i = 0; i < 2; i++){
    //     printf("책 %s의 정보 \n", book_list[i].name);
    //     printf("저자 : %s \n", book_list[i].auth);
    //     printf("출판사 : %s \n", book_list[i].publ);

    //     if (book_list[i].borrowed == 0){
    //         printf("안빌려짐 \n ");
    //     } else {
    //         printf("빌려짐 \n");
    //     }
    // }
};

struct test{
    int a, b;

    // struct test st;
    // struct test *ptr;

    // ptr = &st; // 구조체 "변수" 이기에 &로 주소값을 얻어옴. (리스트는 그냥 *ptr = arr 와 같은 형태)

    // (*ptr).a = 1; // (*ptr).a 로 하는 이유는, 연산자 "." 가 "*" 보다 우선순위가 높기에 괄호를 써줌으로써 .a가 포인터 ptr을 가르킬 수 있도록. 하였음.
    // (*ptr).b = 2; 

    // ptr->a = 3; // 위 (*ptr).a 를 이렇게  표기할 수 있음
    // ptr->b = 4;

    // printf("st a : %d \n", st.a);
    // printf("st b : %d \n", st.b);
};

struct pstest{
    int c;
    int *pointer;

    // struct pstest t;
    // struct pstest *pt = &t;

    // int i = 0;

    // t.pointer = &i;
    // *t.pointer = 3;

    // printf("i : %d \n", i);

    // *pt->pointer = 4;

    // printf("i : %d \n", i);

    // ----

    // struct pstest t, t2;
    // struct pstest *pt = &t;

    // pt->c = 0;

    // add_one(&t.c);

    // printf("t.c : %d \n", t.c);

    // add_one(&pt->c); // -> 가 우선순위가 더 높으니 포인터 pt가 가르키는 c의 메모리값에 1을 더함

    // printf("t.c : %d \n", t.c);

};

struct assign_test{
    int i;
    char str[20];

    // struct assign_test a,b;

    // b.i = 3;
    // copy_str(b.str, "hello world");

    // a = b;

    // printf("a.str : %s \n", a.str);
    // printf("a.i : %d \n", a.i);
};

struct employee{
    int age;
    int salary;
};

struct company{
    struct employee data;
    char name[10];
};

struct AA function(int j);

struct AA{
    int i;
};

struct obj{
    char name[20];
    int x,y;
} Ball = {"abc", 10, 2}; // 이렇게 정의할 수도 있음

union A{
    int i;
    char j;
};

enum {red = 3, blue, white, black};

int copy_str(char *dest, const char *src);
int add_one(int *a);
int set_struct(struct assign_test *a, int i, char *str);

int main(){
    int palette = black;
    printf("%d \n", palette);

    return 0;
}

int copy_str(char *dest, const char *src){
    while (*src){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}

int add_one(int *a){
    *a += 1;
    return 0;
}

int set_struct(struct assign_test *a, int i, char *str){
    a->i = i;
    copy_str(a->str, str);

    return 0;
}

int assign_func(){
    struct assign_test a;

    set_struct(&a, 10, "hello world");

    printf("i : %d / str : %s \n", a.i, a.str);
    return 0;
}

int double_struct(){
    struct company kim;

    kim.data.age  = 31;
    kim.data.salary = 300;

    printf("age : %d / salary %d \n", kim.data.age, kim.data.salary);

    return 0;
}

struct AA function(int j){
    struct AA A;
    A.i = j;

    return A;
}

int return_struct(){
    struct AA a;

    a = function(10);

    printf("a.i : %d \n", a.i);

    return 0;
}

int new_var(){
    printf("%s, %d, %d \n",Ball.name, Ball.x, Ball.y);

    return 0;
}

int union_func(){
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j);
    return 0;
}

int enum_func(){
    int palette = red;

    switch (palette){
        case red:
            printf("red \n");
            break;

        case blue:
            printf("blue \n");
            break;
        case white:
            printf("white \n");
            break;
        case black:
            printf("black \n");
            break;
    } 
    return 0;
}
