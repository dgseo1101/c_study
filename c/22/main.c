#include <stdio.h>

#define ALIVE 0x1      // 2 진수로 1
#define WALKING 0x2    // 2 진수로 10
#define RUNNING 0x4    // 2 진수로 100
#define JUMPING 0x8    // 2 진수로 1000
#define SLEEPING 0x10  // 2 진수로 10000
#define EATING 0x20    // 2 진수로 100000

// int inc_second(int second) {return (++second) % 60;}
// 위 보단 아래와 같이 나눗셈을 피해주는 것이 좋음 (나눗셈이 덧셈보다 10배 느림.)
int inc_second(int second) {
    ++second;
    if (second >= 60) return 0;
    return second;
}

int shift_example(){
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);

    printf("%d 를 32 로 나누면 : %d \n", i, i/32);
    printf("%d 를 5칸 쉬프트 하면 %d \n", i, i>>5);

    return 0;
}

struct HUMAN {
    int is_Alive;
    int is_Walking;
    int is_Running;
    int is_Jumping;
    int is_Sleeping;
    int is_Eating;
};

int human_exmaple(){
    int my_status = ALIVE | WALKING | EATING;

    if (my_status & ALIVE) {
    printf("I am ALIVE!! \n");
    }
    if (my_status & WALKING) {
    printf("I am WALKING!! \n");
    }
    if (my_status & RUNNING) {
    printf("I am RUNNING!! \n");
    }
    if (my_status & JUMPING) {
    printf("I am JUMPING!! \n");
    }
    if (my_status & SLEEPING) {
    printf("I am SLEEPING!! \n");
    }
    if (my_status & EATING) {
    printf("I am EATING!! \n");
    }
    return 0;
}

int bit_odd(){
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);

    if (i & 1){
        printf("%d 는 홀수 \n", i);
    } else {
        printf("%d 는 짝수 \n", i);
    }

    return 0;
}

int sum_ex(){
    int sum = 0;
    for (int i = 0; i<10 + 1; i++){
        sum += i;
    }

    int ga_sum;
    ga_sum = (10 + 1) * 10 / 2;

    printf("%d %d", sum , ga_sum);
}

void loop_break(int n){
    int one_bit;
    while (n != 0) {
        if (n & 1) one_bit++;
        if (n & 2) one_bit++;
        if (n & 4) one_bit++;
        if (n & 8) one_bit++;
        n >>= 4;
    }
}

void print_a(){
    printf("a");
}

int less_loop(){
    for (int i = 0; i < 3; i++){
        print_a();
    }

    print_a();
    print_a();
    print_a();
}

int if_split(){
    int i;
    if (i == 1) {
    } else if (i == 2) {
    } else if (i == 3) {
    } else if (i == 4) {
    } else if (i == 5) {
    } else if (i == 6) {
    } else if (i == 7) {
    } else if (i == 8) {
    }

    // 위에 보단 2의 배수로 쪼개는게 훨씬 효율적임.

    if (i <= 4) {
        if (i <= 2) {
            if (i == 1) {
                /* i is 1 */
            } else {
                /* i must be 2 */
            }
        } else {
            if (i == 3) {
                /* i is 3 */
            } else {
                /* i must be 4 */
            }
        }
    } else {
        if (i <= 6) {
            if (i == 5) {
                /* i is 5 */
            } else {
                /* i must be 6 */
            }
        } else {
            if (i == 7) {
                /* i is 7 */
            } else {
                /* i must be 8 */
            }
        }
    }

    // 위와같이 순차적일땐 swith case 사용.

    switch (i) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
}

char* Condition_String1(int condition) {
    switch (condition) {
        case 0:
            return "EQ";
        case 1:
            return "NE";
        case 2:
            return "CS";
        case 3:
            return "CC";
        case 4:
            return "MI";
        case 5:
            return "PL";
        case 6:
            return "VS";
        case 7:
            return "VC";
        case 8:
            return "HI";
        case 9:
            return "LS";
        case 10:
            return "GE";
        case 11:
            return "LT";
        case 12:
            return "GT";
        case 13:
            return "LE";
        case 14:
            return "";
        default:
            return 0;
    }
}
// 위 함수같은 경우 괜찮긴 하지만 가능하다면 아래와 같은 룩업테이블로 작성해주기.

char* Condition_String2(int condition) {
    if ((unsigned)condition >= 15) {
        return 0;
    }
    char* table[] = {"EQ", "NE", "CS", "CC", "MI", "PL", "VS",
                    "VC", "HI", "LS", "GE", "LT", "GT", "LE"};
    return table[condition];
}

int print_time(){
    int i;
    for (i = 0; i < 3; i ++){
        print_a();
    }

    // 위에 보단 아래가 더 빠름 (함수 사용 안하니)

    for (i = 0; i < 3; i ++){
        printf("a");
    }
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}
// 함수보단 인라인 함수가 더 빠름.
__inline int imax(int a, int b){
    if (a > b) return a;
    return b;
}

struct big{
    int arr[1000];
    char str[1000];
};

// void modify(struct big arg){ /* 무언갈 한다. */ }
// // 위에 보단 아래와 같이 포인터로 넘겨주는게 무의미한 메모리 낭비를 하지 않음.
// void modify(struct big *arg) {/* 무언갈 한다. */}

int main() {
    // modify();
    return 0;
}