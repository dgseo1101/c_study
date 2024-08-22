#include <stdio.h>

void temp_func1(){
    int temp_arr[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d", temp_arr[-1]);
}

int* input_result(int arr[], int s){
    for (int i = 0; i<s; i++){
        printf("%d 번째 성적은 ? : ",i+1);
        scanf("%d", &arr[i]);
    }

    return arr;
}

int* sort_array(int arr[], int s){
    for (int i = 0; i<s; i++){
        printf("%d",arr[i]);
    }

    return arr;
}

int cal_aver(int arr[], int s){
    int i,aver,sum=0;
    for (i=0; i<s; i++){
        sum += arr[i];
    }
    aver = sum/s;
    return aver;
}

int main() {
    // temp_func1();

    int s = 5;
    int arr[s];
    int aver; 
    input_result(arr , s);

    sort_array(arr, s);
    // aver = cal_aver(arr,s);

    return 0;
}