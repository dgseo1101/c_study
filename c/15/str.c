int copy_str(char *str1, char *str2){
    while (*str2){
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';

    return 1;
}