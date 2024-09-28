#include <stdio.h>

#define MaxSize 100


struct ElemenType
{
    int value;
    int index;
    static const ElemenType ERROR;
}

    typedef struct SNode *Stack;
    struct SNode
    {
        ElemenType data[MaxSize];
        int top;

    };

    void Push(Stack PtrS, ElemenType item)
    {
        if (PtrS->top == MaxSize - 1)
        {
            printf("the stack is full");
            return;
        }
        else
        {
            PtrS->data[++(PtrS->top)] = item;
            return;
        }
    }

    ElemenType Pop(Stack PtrS)
    {
        if (PtrS->top == -1)
        {
            printf("the stack is empty");
            return ERROR;
        }
        else
        {
            return PtrS->data[(PtrS->top)--];
        }
    }
