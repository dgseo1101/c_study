#include <stdio.h>
#include <stdlib.h>

void malloc_0(){
    int SizeOfArray;
    int *arr;

    printf("만들고 싶은 배열 길이 : ");
    scanf("%d", &SizeOfArray);

    arr = (int *)malloc(sizeof(int) * SizeOfArray); // 만든 arr은, 힙 영역에 위치하고 있음. (힙은 자유롭게 메모리를 할당, 해제 가능.)

    free(arr);
}

void student_mean(){
    int student;
    int i, input;
    int *score;
    int sum = 0;

    printf("학생 수 : ");
    scanf("%d", &student);

    score = (int *)malloc(student * sizeof(int));

    for (i = 0; i < student; i++){
        printf("학생 %d 의 점수 : ", i);
        scanf("%d", &input);

        score[i] = input;
        sum += input;
    }

    printf("전체 학생 평균 점수 : %d \n", sum/student);
    free(score);
}

void array_2d(){
    int i, x, y;
    int **arr;

    printf("arr[x][y] x,y = ");
    scanf("%d %d", &x, &y);

    arr = (int **)malloc(sizeof(int *) * x);

    for (i = 0; i<x; i++){
        arr[i] = (int *)malloc(sizeof(int) * y);
    }

    printf("생성 완료 \n");

    for (i = 0; i < x; i++){
        free(arr[i]);
    }

    free(arr);
}

void input_student_score(){
    int i,j, input, sum = 0;
    int subject, students;
    int **arr;

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생 수 : ");
    scanf("%d", &students);

    arr = (int **)malloc(sizeof(int *) * subject);

    for (i = 0; i<subject; i++){
        arr[i] = (int *)malloc(sizeof(int) * students);
    }

    for (i = 0; i<subject; i++){
        printf("과목 %d 점수 ---- \n", i);

        for (j = 0; j < students; j++){
            printf("학생 %d 의 점수 : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    for (i = 0; i<subject; i++){
        sum = 0;
        for (j = 0; j<students; j++){
            sum += arr[i][j];
        }

        printf("과목 %d의 평균 점수 : %d \n", i, sum/students);
    }

    for (i = 0; i < students; i++){
        free(arr[i]);
    }

    free(arr);
}

void print_arr(int width, int (*arr)[width], int height){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

void real_2d_arr(){
    int width, height;
    
    printf("배열 행 크기 : ");
    scanf("%d", &width);
    printf("배열 열 크기 : ");
    scanf("%d", &height);

    int (*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int)); // malloc은 상당히 느린 함수 중 하나임. -> 호출을 최소한으로 가져가기.

    for (int i = 0; i < height; i ++){
        for (int j= 0; j < width; j ++){
            int data;

            scanf("%d", &data);
            arr[i][j] = data;
        }
    }

    print_arr(width, arr, height);

    free(arr);
}

void get_average(int num_student, int num_subject, int (*score)[num_student]){
    int i, j, sum;

    for (i = 0; i < num_subject; i++){
        sum = 0;
        for (j = 0; j < num_student; j++){
            sum += score[i][j];
        }

        printf("과목 %d 의 평균 점수 : %d \n", i, sum/num_student);
    }
}

int main(int argc, char **argv){
    int subject, student;

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생의 수 : ");
    scanf("%d", &student);

    int (*score)[student];
    score = (int(*)[student])malloc(sizeof(int) * subject * student);

    for (int i = 0; i < subject; i++){
        printf("과목 %d 의 점수 --- \n", i);

        for (int j = 0; j < student; j++){
            printf("학생 %d의 점수 : ", j);
            scanf("%d", &score[i][j]);
        }
    }

    get_average(student, subject, score);
    free(score);

    return 0;
}