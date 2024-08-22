#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Something{
    int a,b;
};

void struct_malloc(){
    struct Something *arr;
    int size, i;

    printf("원하는 구조체 배열의 크기 : ");
    scanf("%d", &size);

    arr = (struct Something *)malloc(sizeof(struct Something) * size);

    for (i = 0; i < size; i++){
        printf("arr[%d].a : ", i);
        scanf("%d", &arr[i].a);
        printf("arr[%d].b : ", i);
        scanf("%d", &arr[i].b);
    }

    for (i = 0; i < size; i++){
        printf("arr[%d].a : %d, arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);
    }

    free(arr);
}

struct Node{
    int data;
    struct Node* nextNode;
};

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

struct Node* InsertNode(struct Node* current, int data){
    struct Node* after = current->nextNode;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = after;

    current->nextNode = newNode;

    return newNode;
}

void DestroyNode(struct Node *destroy, struct Node *head){
    struct Node *next = head;

    if (destroy == head){
        free(destroy);
        return;
    }

    while (next){
        if (next->nextNode == destroy){
            next->nextNode = destroy->nextNode;
        }

        next = next->nextNode;
    }
    free(destroy);
}

void PrintNodeFrom(struct Node* from){
    while (from){
        printf("노드의 데이터 : %d \n", from->data);
        from = from->nextNode;
    }
}

void node_ex(){
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);

    PrintNodeFrom(Node1);
}

void memcpy_ex(){
    char str[50] = "I love C";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1); // str로 부터 strlen(str) + 1 만큼의 문자를 str2로 복사해라
    memcpy(str3, "Hello", 6);
    
    printf("%s \n", str);   
    printf("%s \n", str2);
    printf("%s \n", str3); 
}

void memmove_ex(){
    char str[50] = "I love Chewing C hahaha";

   printf("%s \n", str);
   printf("after memmove \n");
   memmove(str + 23, str + 17, 6); // 얘는 str+17 에서 6개의 문자를 str+23 에 옮김. memmove는 memcpy와 비슷하지만 memcpy와 달리 메모리 공간이 겹쳐도 됨.
   printf("%s \n", str);
}

int main(){
   int arr[10] = {1,2,3,4,5};
   int arr2[10] = {1,2,3,4,5};

   if (memcmp(arr, arr, 5) == 0)
        printf("arr 과 arr2은 일치 \n");
    else
        printf("arr 과 arr2 는 불일치 \n");

   return 0;
}