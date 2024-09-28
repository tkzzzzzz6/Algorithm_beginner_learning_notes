#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void InitList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}
void DestroyList(SqList *L)
{
    free(L);
}
bool ListEmpty(SqList *L)
{

    return (L->length == 0);
}
int ListLength(SqList *L)
{
    return (L->length);
}
void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}
bool GetElem(SqList *L, int i, ElemType &e)
{
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}
int LocateElem(SqList *&L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i > L->length)
        return 0;
    else
        return i + 1;
}
bool ListInsert(SqList *&L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return false;
    i--;
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}
bool ListDelete(SqList *&L, int i, ElemType &e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return false;
    i--;
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}
// 编写函数,将X插入到一个有序的线性表（按顺序存储从小到大），同时保持线性表有序

int main()
{
    printf("(1)初始化顺序表L\n");
    SqList *L;
    InitList(L);

    printf("(2)输入顺序表的长度M:\n");
    int M;
    scanf("%d", &M);

    printf("(3)依次插入M个元素\n");
    for (int i = 0; i < M; i++)
    {
        int temp;
        scanf("%d", &temp);
        ListInsert(L, L->length + 1, temp);
    }

    printf("当前顺序表：");
    DispList(L);

    printf("(4)输入要插入的数据元素的值:\n");
    int x;
    scanf("%d", &x);

    // 查找插入位置
    int pos = 1;
    while (pos <= L->length && L->data[pos-1] < x)
        pos++;

    if (ListInsert(L, pos, x))
        printf("插入成功\n");
    else
        printf("插入失败\n");

    printf("(5)输出插入后的顺序表：");
    DispList(L);

    DestroyList(L);
    return 0;
}