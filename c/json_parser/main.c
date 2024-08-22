#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 

#define token_count 20

typedef enum _token_type{
    token_string,
    token_number,
    token_object,
    token_array,
    token_true,
    token_false,
    token_null,
} token_type;

typedef struct _token{
    token_type type;
    union {             // 두 종류 중 한 종류만 저장할 것이므로 공용체로 만듦
        char *string;       // 문자열 포인터
        double number;      // 실수형 숫자
    };
    bool is_array;
} TOKEN;

typedef struct _json{
    TOKEN tokens[token_count];
} JSON;

char *read_file(char *file_name, int *read_size, int debug){
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL){
        printf("read error \n");
        return NULL;
    }

    if (debug){
        char c;
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }
    }

    int size;
    char *buffer;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = malloc(size + 1);
    memset(buffer, 0, size + 1);

    if (fread(buffer, size, 1, fp) < 1){
        *read_size = 0;
        free(buffer);
        fclose(fp);
        return NULL;
    }

    *read_size = size;

    fclose(fp);

    return buffer;
}

int parse_json(char *doc, int size, JSON *json_data){
    int token_index = 0;
    int pos = 0;

    if (doc[pos] != '{'){
        return -1;
    }

    pos ++;

    while (pos < size){
        switch (doc[pos]){
            case '"':{
                
                char *begin = doc + pos + 1;

                char *end = strchr(begin, '"');
                if (end == NULL)
                    break;
                

                int string_len = end - begin;
                json_data->tokens[token_index].type = token_string;
                json_data->tokens[token_index].string = malloc(string_len + 1);
                memset(json_data->tokens[token_index].string, 0, string_len + 1);
                memcpy(json_data->tokens[token_index].string, begin, string_len);

                token_index++;

                pos = pos + string_len + 1;
            }
            break;

            case '[':{
                
                pos ++;
                while(doc[pos] != ']'){
                    if (doc[pos] == '"'){
                        char *begin = doc + pos + 1;

                        char *end = strchr(begin, '"');
                        if (end == NULL)
                            break;
                        

                        int string_len = end - begin;
                        json_data->tokens[token_index].type = token_string;
                        json_data->tokens[token_index].string = malloc(string_len + 1);
                        json_data->tokens[token_index].is_array = true;
                        memset(json_data->tokens[token_index].string, 0, string_len + 1);
                        memcpy(json_data->tokens[token_index].string, begin, string_len);

                        token_index++;

                        pos = pos + string_len + 1;

                    } else if (doc[pos] >= '0' && doc[pos] <= '9' || doc[pos] == '-'){
                        char *begin = doc + pos;
                        char *end;
                        char *buffer;

                        end = strchr(doc+pos, ',');
                        if (end == NULL){
                            end  = strchr(doc + pos, '}');
                            if (end == NULL){
                                break;
                            }
                        }

                        int string_len = end - begin;

                        buffer = malloc(string_len + 1);
                        memset(buffer, 0, string_len + 1);

                        memcpy(buffer, begin, string_len);

                        json_data->tokens[token_index].type = token_number;
                        json_data->tokens[token_index].number = atof(buffer);
                        json_data->tokens[token_index].is_array = true;

                        free(buffer);

                        token_index ++;

                        pos = pos + string_len + 1;
                    }
                    pos++;
                }

            }

            case '{':{
                // object 처리
            }

            case '0': case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9': case '-': {
                char *begin = doc + pos;
                char *end;
                char *buffer;

                end = strchr(doc+pos, ',');
                if (end == NULL){
                    end  = strchr(doc + pos, '}');
                    if (end == NULL){
                        break;
                    }
                }

                int string_len = end - begin;

                buffer = malloc(string_len + 1);
                memset(buffer, 0, string_len + 1);
                memcpy(buffer, begin, string_len);

                json_data->tokens[token_index].type = token_number;
                json_data->tokens[token_index].number = atof(buffer);

                free(buffer);

                token_index ++;

                pos = pos + string_len + 1;


            }
            break;
        }

        pos ++;
    }
}

void free_json(JSON *json_data){
    for (int i = 0; i < token_count; i++){
        if (json_data->tokens[i].type == token_string){
            free(json_data->tokens[i].string);
        }
    }
}

int compare(char *str1, char *str2){
    while (*str1){
        if (*str1 != *str2){
            str1++;
            str2++;
        } else {
            return 1;
        }
    }

    return 0;
}

char *search_key_str(JSON *json_data, char *key){
    for (int i = 0; i < token_count; i++){
        if (json_data->tokens[i].type == token_string && compare(json_data->tokens[i].string, key) == 1){
            if (json_data->tokens[i + 1].type == token_string){
                return json_data->tokens[i + 1].string;
            }
        }
    }
    return NULL;
}

char *search_array_str(JSON *json_data, char *key, int index){
    for (int i = 0; i < token_count; i ++){
        if (json_data->tokens[i].type == token_string && compare(json_data->tokens[i].string, key) == 1){
            if (json_data->tokens[i + 1 + index].is_array == true){
                if (json_data->tokens[i + 1 + index].type == token_string){
                    return json_data->tokens[i + 1 + index].string;
                } 
                // else if (json_data->tokens[i + 1 + index].type == token_number){
                //     return json_data->tokens[i + 1 + index].number;
                // }
            }
        }
    }

    return NULL;
}

int search_array_count(JSON *json_data, char *key){
    for (int i = 0; i < token_count; i++){
        if (json_data->tokens[i].type == token_string && compare(json_data->tokens[i].string, key) == 1){
            int j = 0;
            while (json_data->tokens[i + j].is_array == true){
                j ++;
            }

            return j;
        }
    }
    return -1;
}

double search_number(JSON *json_data, char *key){
    for (int i = 0; i < token_count; i++){
        if (json_data->tokens[i].type == token_string && compare(json_data->tokens[i].string, key) == 1){
            if (json_data->tokens[i + 1].type == token_number){
                return json_data->tokens[i + 1].number;
            }
        }
    }

    return -1;
}

int main(){

    char *json_path = "./dgseo.json";
    int read_size; // 파일 크기 
    char *doc = read_file(json_path, &read_size, 0); // json 파일 읽고 파일 크기 구하기
    if (doc == NULL){
        return -1;
    }

    JSON json_data = {0, };

    parse_json(doc, read_size, &json_data);

    printf("Title : %s \n", search_key_str(&json_data, "Title"));

    // for (int i = 0; i < token_count; i++){
    //     if (json_data.tokens[i].is_array == false){
    //         printf("%s : ", json_data.tokens[i].string);
    //         char *value;
    //         value = search_key_str(&json_data, json_data.tokens[i].string);
            
    //         if (value == NULL){
    //             int value = search_number(&json_data, json_data.tokens[i].string);

    //             if (value == -1){
    //                 printf("debug : error \n");
    //             }

    //             printf("%d \n", value);
    //         }
    //         printf("%s \n", value);
    //     } else {
    //         printf("\n    %s", json_data.tokens[i].string);
    //     }
    // }


    free_json(&json_data);

    free(doc);

    return 0;
}