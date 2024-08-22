#include <stdio.h>
#include "human.h"
#include "str.h"

struct Human create_human(char *name, int age, int gender){
    struct Human human;

    human.age = age;
    human.gender = gender;
    copy_str(human.name, name);

    return human;
};

int print_human(struct Human *human){
    printf("name : %s \n", human->name);
    printf("age : %d \n", human->age);
    if (human->gender == MALE){
        printf("gender : male \n");
    } else if (human->gender == FEMALE){
        printf("gender : female \n");
    }

    return 0;
}