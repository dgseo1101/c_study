int compare(char *str1, char *str2){
    while (*str1){
        if (*str1 != *str2){
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1;
    return 0;
}

int copy_str(char *str, char *src){
    while(*src){
        *str = *src;
        str++;
        src++;
    }

    *str = '\0';

    return 0;
}