
#include <stdio.h>

#define MaxSize 100

struct ElemenType
{
    int value;
    int index;
};

struct DStack
{
    ElemenType data[MaxSize];
    int top1;
    int top2;
} S;

void Push(struct DStack *Ptrs, ElemenType item, int tag)
{
    if (Ptrs->top1 + 1 == Ptrs->top2)
    {
        printf("stack is full");
        return;
    }
    if (tag == 1)
    {
        Ptrs->data[++Ptrs->top1] = item;
    }
    else
    {
        Ptrs->data[--Ptrs->top2] = item;
    }
}

ElemenType Pop(struct DStack *Ptrs, int tag)
{
    ElemenType emptyElement = {-1, -1};
    if (tag == 1)
    {
        if (Ptrs->top1 == -1)
        {
            printf("stacl 1 is empty");
            return emptyElement;
        }
        else
            return Ptrs->data[Ptrs->top1--];
    }
    if (tag == 2)
    {
        if (Ptrs->top2 == MaxSize)
        {
            printf("stack 2 is empty");
            return emptyElement;
        }
        else
            return Ptrs->data[Ptrs->top2++];
    }
    return emptyElement;
}

int main()
{
    struct DStack mystack;
    mystack.top1 = -1;
    mystack.top2 = MaxSize;

    // push element1 into stack 1
    ElemenType element1 = {10, 1};
    Push(&mystack, element1, 1);

    // push element2 into stack 2
    ElemenType element2 = {20, 2};
    Push(&mystack, element2, 2);

    // push element3 into stack 1
    ElemenType element3 = {30, 1};
    Push(&mystack, element3, 1);

    // push element4 into stack 2
    ElemenType element4 = {40, 2};
    Push(&mystack, element4, 2);

    // print all the elements in the stack
    printf("stack 1 elements: ");
    for (int i = 0; i <= mystack.top1; i++)
    {
        printf("%d ", mystack.data[i].value);
    }
    printf("\n");

    printf("stack 2 elements: ");
    for (int i = MaxSize - 1; i >= mystack.top2; i--)
    {
        printf("%d", mystack.data[i].value);
    }
    printf("\n");

    // pop element from stack 1
    ElemenType popElement1 = Pop(&mystack, 1);
    printf("pop element from stack 1:%d\n", popElement1.value);
    // pop element from stack 2
    ElemenType popElement2 = Pop(&mystack, 2);
    printf("pop element from stack 2:%d\n", popElement2.value);

    // print all the elements in the stack
    printf("stack 1 elements: ");
    for (int i = 0; i <= mystack.top1; i++)
    {
        printf("%d ", mystack.data[i].value);
    }
    printf("\n");

    printf("stack 2 elements: ");
    for (int i = MaxSize - 1; i >= mystack.top2; i--)
    {
        printf("%d", mystack.data[i].value);
    }
    printf("\n");

    return 0;
}