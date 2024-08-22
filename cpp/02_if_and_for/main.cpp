#include <iostream>

int main(){
    int i, sum = 0;

    for (i = 0; i < 10; i++){
        if (i % 2 == 0 && i != 0){
            std::cout << i << std::endl;
        } else {
            sum += i;
            std::cout << sum << std::endl;
        }
    }

    return 0;
}

// while (1) // 괄호 안에 조건문

// int input_value;
// std::cin >> input_value;

// switch (input_value){

// case 1:
//     std::cout << "case 1" << std::endl;
//     break;

// case 2:
//     std::cout << "case 2" << std::endl;
//     break;

// default:
//     std::cout << "default" << std::endl;
//     break;

// }