// for the linked list to create a stack,it is apparent that the head of the linked list is suitable to insert and delete the element,so we use the head of the linked list to represent the stack
#include <stdio.h>
#include <stack>
#define MaxSize 100

typedef struct SNode *stack;

struct ElemenType
{
    int value;
    int index;
};

struct SNode
{
    ElemenType data[MaxSize];
    struct SNode *next;
};

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->next = NULL;
    return S;
}

int IsEmpty(Stack S)
{
    // judge whether the stack is empty,if it is empty,return 1,otherwise return 0
    return (S->next == NULL);
}

void Push(ElemenType Element,Stack S){
    struct SNode *tmpcell;
    tmpcell = (struct SNode *)malloc(sizeof(struct SNode));
    tmpcell->Element = item;
    tmpcell->next = S->next;
    S->next = tmpcell;
}

ElmenType Pop(Stack S){
    struct SNode *firstcell;
    ElemenType TopElem;
    is (IsEmpty(S)){
        printf("the stack is empty\n");
        return NULL;
    }else{
        firstcell = S->next;
        S->next = firstcell->next;
        TopElem = firstcell->Element;
        free(firstcell);
        return TopElem;
    }
}