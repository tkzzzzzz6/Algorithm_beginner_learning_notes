#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MaxSize 50

typedef struct city{
    char code[4];
    char name[10];
    char describe[16];
} ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *L,ElemType a[],int n){
    // create the sqlist entirely
    int i;
    L = (SqList *)malloc(sizeof(SqList));
    for (i = 0; i < n;i++)
        L->data[i] = a[i];
    L->length = n;
}

void ShowList(SqList *L){
    int i;
    for (i = 0; i < L->length; i++){
        printf("Code: %s, Name: %s, Description: %s\n", L->data[i].code, L->data[i].name, L->data[i].describe);
    }
}

int main(){
    SqList *L;
    ElemType a[3] = {
        {"001","Beijing","The capital of China"},
        {"002","Shanghai","The biggest city in China"},
        {"003","Guangzhou","The city of Canton"}
    };
    CreateList(L,a,3);
    ShowList(L);
    return 0;
}