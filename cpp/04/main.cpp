#include <iostream>

void new_ex(){
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
}

void new_list_ex(){
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;

    int *list = new int[arr_size]; // list 할당은 new[] 제거는 delete[]

    for (int i = 0; i < arr_size; i++){
        std::cin >> list[i];
    }

    for (int i = 0; i < arr_size; i++){
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }

    delete[] list;
}

typedef struct Animal{
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal; 

void create_animal(Animal *animal){
    std::cout << "동물의 이름 : ";
    std::cin >> animal->name;

    std::cout << "동물의 나이 : ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal *animal){
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal *animal){
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력 : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결 : " << animal->clean << std::endl;
}

int main(){
    Animal *list[10];
    int animal_num = 0;

    for (;;){
        std::cout << "1, 동물 추가하기" << std::endl;
        std::cout << "2, 놀기" << std::endl;
        std::cout << "3, 상태보기" << std::endl;

        int input;
        std::cin >> input;

        switch (input){
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);

                animal_num++;
                break;
            case 2: 
                std::cout << "누구랑 놀게 ? : ";
                std::cin >> play_with;

                if (play_with < animal_num) play(list[play_with]);

                break;

            case 3:
                std::cout << "누구 상태를 확인하게 ? :";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(list[play_with]);

                break;
        }

        for (int i = 0; i != animal_num; i++){
            one_day_pass(list[i]);
        }
    }

    for (int i = 0; i != animal_num; i++){
        delete list[i];
    }


    return 0;
}