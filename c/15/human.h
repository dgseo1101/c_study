enum {MALE, FEMALE};

struct Human{
    char name[20];
    int age;
    int gender;
};

struct Human create_human(char *name, int age, int gender);
int print_human(struct Human *human);