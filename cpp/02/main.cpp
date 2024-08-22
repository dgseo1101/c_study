#include <iostream>

void var_def(){
    int i;
    char c;
    double d;
    float f;

    int arr[10];
    int *parr = arr;
    int *pi = &i;
}

void sum_for(){
    int i;
    int sum = 0;

    for (i = 0; i < 10; i++){
        sum += i;
    }

    std::cout << "합은 : " << sum << std::endl;
}

void for_if_ex(){
    int lucky_number = 3;

    int user_input;

    while (1){
        std::cout << "입력 : ";
        std::cin >> user_input;

        if (lucky_number == user_input){
            std::cout << "맞췄습니다" << std::endl;
            break;
        } else {
            std::cout << "다시 생각해보세요" << std::endl;
        }
    }
}

using std::cout;
using std::endl;
using std::cin;

int main(){
    int user_input;

    cout << "저의 정보를 표시해줍니다" << endl;
    cout << "1, 이름" << endl;
    cout << "2, 나이" << endl;
    cout << "3, 성별" << endl;

    cin >> user_input;

    switch (user_input){
    case 1:
        cout << "dgseo" << endl;
        break;
    case 2:
        cout << "23" << endl;
        break;
    case 3:
        cout << "man" << endl;
        break;
    default:
        cout << "end" << endl;
        break;
    }

    return 0;
}